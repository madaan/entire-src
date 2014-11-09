import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by lenovo on 14-9-15.
 */
public class D {

    int[][] rotate(int[][] s) {
        int[][] res = new int[4][2];
        int min0 = 100, min1 = 100;
        for (int i = 0; i < 4; ++i) {
            res[i][0] = -s[i][1];
            res[i][1] = s[i][0];
            min0 = Math.min(min0, res[i][0]);
            min1 = Math.min(min1, res[i][1]);
        }
        for (int i = 0; i < 4; ++i) {
            res[i][0] -= min0;
            res[i][1] -= min1;
        }
        return res;
    }

    private void run() {

        try {

            Scanner scanner = new Scanner(new File("D-small-attempt0 (1).in"));
            PrintWriter writer = new PrintWriter(new File("Dss.out"));

            int testNumber = scanner.nextInt();

            for (int cs = 1; cs <= testNumber; ++cs) {
                int width = scanner.nextInt();
                int height = scanner.nextInt();
                int n = scanner.nextInt();
                int[][][][] blocks = new int[7][4][][];
                int[][] blocks0 = {{0, 0}, {1, 0}, {1, 1}, {2, 1}}; blocks[0][0] = blocks0;
                int[][] blocks1 = {{0, 1}, {1, 0}, {1, 1}, {2, 0}}; blocks[1][0] = blocks1;
                int[][] blocks2 = {{0, 0}, {1, 0}, {2, 0}, {2, 1}}; blocks[2][0] = blocks2;
                int[][] blocks3 = {{0, 1}, {1, 1}, {2, 1}, {2, 0}}; blocks[3][0] = blocks3;
                int[][] blocks4 = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; blocks[4][0] = blocks4;
                int[][] blocks5 = {{0, 0}, {1, 0}, {2, 0}, {3, 0}}; blocks[5][0] = blocks5;
                int[][] blocks6 = {{0, 1}, {1, 0}, {1, 1}, {1, 2}}; blocks[6][0] = blocks6;
                for (int i = 0; i < 7; ++i)
                    for (int j = 1; j < 4; ++j) {
                        blocks[i][j] = rotate(blocks[i][j - 1]);
                    }

                boolean[][] field = new boolean[height][width];
                boolean gameFailed = false;
                for (int kk = 0; kk < n; ++kk) {
                    int t = scanner.nextInt();
                    int r = scanner.nextInt();
                    int x = scanner.nextInt();

                    if (gameFailed) continue;

                    int[][] block = blocks[t - 1][r];

                    int row = -1;
                    for (int k = 0; k < 4; ++k) {
                       // System.out.println(block[k][0] + " " + block[k][1]);
                        int col = x + block[k][1];
                        for (int rr = height - 1; rr >= 0; --rr) {
                            if (!field[rr][col] && (rr == 0 || field[rr - 1][col])) {
                         //       System.out.println("d " + row);
                                row = Math.max(row, rr + block[k][0]);
                                break;
                            }
                        }
                    }
                   // System.out.println(row);
                    if (row >= height || row == -1) {
                        gameFailed = true;
                        continue;
                    }
                    for (int k = 0; k < 4; ++k) {
                        field[row - block[k][0]][x + block[k][1]] = true;
                    }

                    boolean[] delete = new boolean[height];
                    boolean flag = false;
                    for (int i = 0; i < 4; ++i) {
                        int rr = row - i;
                        if (rr < 0) continue;
                        boolean full = true;
                        for (int col = 0; col < width; ++col)
                            if (!field[rr][col]) full = false;
                        if (full) flag = delete[rr] = true;
                    }
                    if (flag) {
                        int p = 0;
                        for (int rr = 0; rr < height; ++rr) {
                            while (p < height && delete[p]) ++p;
                            for (int cc = 0; cc < width; ++cc) {
                                if (p == height) field[rr][cc] = false;
                                else field[rr][cc] = field[p][cc];
                            }
                            if (p < height) ++p;
                        }
                    }
                }
              //  System.out.println("dsdsadasdas");
                writer.println("Case #" + cs + ":");
                if (gameFailed) {
                    writer.println("Game Over!");
                } else {
                    for (int rr = height - 1; rr >= 0; --rr) {
                        for (int cc = 0; cc < width; ++cc) {
                            if (field[rr][cc]) writer.print('x');
                            else writer.print('.');
                        }
                        writer.println();
                    }
                }

            }
            writer.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new D().run();
    }
}
