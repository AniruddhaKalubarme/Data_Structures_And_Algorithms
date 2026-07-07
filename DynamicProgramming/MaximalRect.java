class Solution {
    void nextSmaller(int[] arr, int[] nse)
    {
        Stack<Integer> s = new Stack<>();
        s.push(-1);

        for(int i = arr.length-1; i>=0; i--)
        {
            int curr = arr[i];

            while(s.peek() != -1 && arr[s.peek()]>=curr)
            {
                s.pop();
            }

            if(s.peek() == -1)
                nse[i] = arr.length;
            else
                nse[i] = s.peek();
            
            s.push(i);
        }
    }

    void prevSmaller(int[] arr, int[] pse)
    {
        Stack<Integer> s = new Stack<>();
        s.push(-1);

        for(int i = 0; i<arr.length; i++)
        {
            int curr = arr[i];

            while(s.peek() != -1 && arr[s.peek()]>=curr)
            {
                s.pop();
            }

            pse[i] = s.peek();
            s.push(i);
        }
    }

    int Area(int[] heights)
    {
        int nse[] = new int[heights.length];
        int pse[] = new int[heights.length];

        nextSmaller(heights, nse);
        prevSmaller(heights, pse);

        int area[] = new int[nse.length];
        int iMax = 0;

        for(int i = 0; i<nse.length; i++)
        {
            area[i] = heights[i] * (nse[i]-pse[i] - 1);
            iMax = Math.max(iMax, area[i]);
        }

        return iMax;
    }

    public int maximalRectangle(char[][] matrix) {

        int heights[] = new int[matrix[0].length];
        Arrays.fill(heights, 0);

        int iMax = 0;

        for(int i = 0; i<matrix.length; i++)
        {
            for(int j = 0; j<matrix[0].length; j++)
            {
                if(matrix[i][j] == '1')
                    heights[j] = heights[j]+1;
                else
                    heights[j] = 0;
            }

            for(int k = 0; k<heights.length; k++)
                System.out.print(heights[k] + "\t");
            System.out.println();

            iMax = Math.max(iMax, Area(heights));
        }


        return iMax;
    }
}