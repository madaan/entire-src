function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%

a1 = [ones(size(X, 1), 1) X];
% X is now 5000 X 401, Theta1 is 25 X 401, z2 is 25 X 5000, 
% one column for each sample
z2 = Theta1 * a1';

a2 = sigmoid(z2);
%a2 is now 26 X 5000. Added for bias
a2 = [ones(1, columns(a2)); a2];
%Theta2 is 10 X 26, a2 is 26 X 5000, z3 is 10 X 5000
z2 = [zeros(1,columns(z2)); z2];
z3 = Theta2 * a2;
a3 = sigmoid(z3);

% a3 is 10 X 5000, each column is a training set
Jt = 0;
yt = zeros(num_labels, m);
for i = 1:m
    yt(y(i), i) = 1;
end
J = -(sum((yt .* log(a3) + (1 - yt) .* log(1 - a3))(:))) / m;

%Earlier implementation : possibly poorer
%for i = 1:m
%    yt = zeros(num_labels, 1);
%    yt(y(i)) = 1;
%    Jt +=  sum(yt .* log(a3(:,i)) + (1 - yt) .* log(1 - a3(:,i)));
%end

% Adding regularization to prevent overfitting

reg = (sum((Theta1 .^ 2)(:)) + sum((Theta2 .^ 2)(:)) - sum(Theta1(:, 1).^ 2(:)) - sum(Theta2(:, 1).^ 2(:)))* (lambda / (2 * m));
J = J + reg;
% Backpropagation algorithm
% since a3 is already calculated for the same data, won't calculate it again
% the network is 400, 25, 10
DELTA1 = zeros(hidden_layer_size, input_layer_size + 1);
DELTA2 = zeros(num_labels, hidden_layer_size + 1);
for i=1:m
    %delta_3 is 10 X 1
    delta_3 = a3(:,i) - yt(:,i);
    %delta_2 is 26 X 1,
    delta_2 = ((Theta2)' * delta_3) .* sigmoidGradient(z2(:,i));
    %DELTA1 should be 25 X 401
    %a1(i,:) is 5000 X 401, delta_2(2:end) * a1(i, :) is thus (25 X 1) * (1 X 401)
    DELTA1 = DELTA1 + delta_2(2:end) * a1(i, :);
    %D2 => 10 X 26, (10 X 1) * (1 X 26)
    DELTA2 = DELTA2 + delta_3 * a2(:,i)';
end
Theta1_grad = DELTA1 / m;
%t1 = [zeros(rows(Theta1), 1) Theta1(:,2:end)];
%Theta1_grad += Theta1_grad + (lambda / m) .* (t1);

Theta1_grad = Theta1_grad + (lambda / m) .* (Theta1);
Theta1_grad(:,1) = Theta1_grad(:,1) - (lambda / m) .* (Theta1(:,1));

Theta2_grad = DELTA2 / m;
Theta2_grad = Theta2_grad + (lambda / m) .* (Theta2);
Theta2_grad(:,1) = Theta2_grad(:,1) - (lambda / m) .* (Theta2(:,1));
%t2 = [zeros(rows(Theta2), 1) Theta2(:,2:end)];
%Theta2_grad += Theta2_grad + (lambda / m) .* (t2);



















% -------------------------------------------------------------

% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
