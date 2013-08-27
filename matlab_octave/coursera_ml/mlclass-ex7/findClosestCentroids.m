function idx = findClosestCentroids(X, centroids)
%FINDCLOSESTCENTROIDS computes the centroid memberships for every example
%   idx = FINDCLOSESTCENTROIDS (X, centroids) returns the closest centroids
%   in idx for a dataset X where each row is a single example. idx = m x 1 
%   vector of centroid assignments (i.e. each entry in range [1..K])
%

% Set K
K = size(centroids, 1);

% You need to return the following variables correctly.
idx = zeros(size(X,1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Go over every example, find its closest centroid, and store
%               the index inside idx at the appropriate location.
%               Concretely, idx(i) should contain the index of the centroid
%               closest to example i. Hence, it should be a value in the 
%               range 1..K
%
% Note: You can use a for-loop over the examples to compute this.
%

for i = 1:rows(X) %assign to all the examples in the training set, a cluster
        mindist = 10000;
        dist = 0;
        resI = 0;
    for j = 1:rows(centroids) %for all the centroids
        dist = 0;
        for r = 1:columns(X) %calculate the squared distance
            dist = dist + (X(i, r) - centroids(j, r)) .^ 2;
        end
        if(dist < mindist) 
            mindist = dist;
            resI = j; %jth centroid is the best
        end
    end
    idx(i) = resI;
end







% =============================================================

end

