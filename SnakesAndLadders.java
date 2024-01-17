package comp2402a5;
// Thanks to Pat Morin for the skeleton of this file!

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.Arrays;

public class SnakesAndLadders {
	/**
	 * Your code goes here
	 * @param r the reader to read from
	 * @param w the writer to write to
	 * @throws IOException
	 */

	public static void doIt(BufferedReader r, PrintWriter w) throws IOException {
		//TODO: Your solution goes here. This example only shows how you can read the input.
		int N = Integer.parseInt(r.readLine());
		int n = N * N;
		
		int [] g = new int[n + 1]; //need to start
		for (String line = r.readLine(); line != null; line = r.readLine()){
			String[] splitted = line.split(" ");
			int u = Integer.parseInt(splitted[0]), v = Integer.parseInt(splitted[1]);
			//w.println(u+" "+v);
			g[u] = v;
		}
		//start at position 1, not 0: go to position n
		w.println(minRolls(g, 1)); 
	}

	//this function is based off of the bfs function from the algorithms file

	/******Note***********
	 * there is a dummy "Node" at the start of the board. I could just slide everything down an index position,
	 * but its easier to keep track of stuff if the numbers are 1-1
	*********************/
	public static int minRolls(int[] board, int s) {
        int e = board.length - 1;

        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[board.length];
        q.add(1); // Start position is 1
        visited[1] = true;
        int rolls = 0;

        while (!q.isEmpty()) {
        	int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int j = q.poll();
                
                for (int dice = 1; dice <= 6; dice++) {
                    int next = j + dice;
					if (next == e) {
						return rolls + 1;
					}

                    if (next <= e && !visited[next]) {
                        visited[next] = true;
                
						int finalPos;
						if (board[next] == 0) {
							finalPos = next;
						} else {
							finalPos = board[next];
						}
                        q.add(finalPos);
                    }
                }
            }
            rolls++;
        }
        return -1; //destination not found
    }

	/**
	 * The driver.  Open a BufferedReader and a PrintWriter, either from System.in
	 * and System.out or from filenames specified on the command line, then call doIt.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader r;
			PrintWriter w;
			if (args.length == 0) {
				r = new BufferedReader(new InputStreamReader(System.in));
				w = new PrintWriter(System.out);
			} else if (args.length == 1) {
				r = new BufferedReader(new FileReader(args[0]));
				w = new PrintWriter(System.out);
			} else {
				r = new BufferedReader(new FileReader(args[0]));
				w = new PrintWriter(new FileWriter(args[1]));
			}
			long start = System.nanoTime();
			doIt(r, w);
			w.flush();
			long stop = System.nanoTime();
			System.out.println("Execution time: " + 1e-9 * (stop-start));
		} catch (IOException e) {
			System.err.println(e);
			System.exit(-1);
		}
	}
}
