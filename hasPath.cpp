bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows<1 || cols<1 ||str == nullptr)
            return false;
        bool visited[rows * cols];
        memset(visited, 0, rows * cols);
        int pathLength = 0;
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                if(hasPathCore(matrix, row，cols, i, j, pathLength, str, visited))
                    return true;
            }
        }
        return false;
    }


bool hasPathCore(char* matrix, int rows, int cols, int i, int j, int pathLength, char* str, bool* visited)
{
    if(str[pathLength] == "\0")
        return true;
    bool fit = false;
    int idx = i * cols + j;
    if(i>=0 && j>=0 && i<row && j<col && matrix[idx] == str[pathLength] && !visited[idx])
    {
        pathLength++;
        visited[idx] = true;
        
        fit = hasPathCore(matrix, row，cols, i-1, j, pathLength, str, visited) ||
        hasPathCore(matrix, row，cols, i, j-1, pathLength, str, visited) || hasPathCore(matrix, row，cols, i+1, j, pathLength, str, visited) ||
        hasPathCore(matrix, row，cols, i, j+1, pathLength, str, visited);

        if(fit == false)
        {
            pathLength--;
            visited[idx] = false;
        }
    }
    return fit;
}















/*class Solution {
public:
    /*
      大家好，我是yishuihan，这个题目是回溯法的典型题目；
      还有八皇后问题也是经典的回溯法例题，大家可以参考;在《剑指offer》书中也给出了八皇后问题的思路；
      不过，那个是在全排列问题中引出来的。其实回溯法也是全排列的一种方案，在本题中，也就是尝试了
      matrix矩阵中所有点作为起点的方法，然后依据这个点进行向四个方向的递归；
      在递归中，不满足题目的会自动出栈回到上一个状态；
    */
  /*  bool hasPath(char* matrix, int rows, int cols, char* str)
    {
       if(matrix==NULL||rows<1||cols<1||str==NULL) return false;
       bool *visited = new bool[rows*cols];
       memset(visited,false,rows*cols);
       for(int i=0;i<rows;i++)
       {
           for(int j=0;j<cols;j++)
           {
               if(hasPathCore(matrix,rows,cols,i, j,str,0,visited))
               {
                   return true;
               }
           }
       }
        delete[] visited;
        return false;
    }

    bool hasPathCore(char* matrix,int rows,int cols,int i,int j,char* str,int k,bool* visited)
    {
        //因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
       int index = i * cols + j;
        //visited[index]==true,说明被访问过了，那么也返回true;
       if(i<0 || i>=rows || j<0 || j>=cols || matrix[index]!=str[k] || visited[index]==true)
               return false;
        //字符串已经查找结束，说明找到该路径了
       if(str[k+1]=='\0') return true;
        //向四个方向进行递归查找,向左，向右，向上，向下查找
       visited[index] = true;//标记访问过
       if(  hasPathCore(matrix, rows, cols, i - 1, j,     str, k + 1, visited)
          ||hasPathCore(matrix, rows, cols, i + 1, j,     str, k + 1, visited)
          ||hasPathCore(matrix, rows, cols, i,     j - 1, str, k + 1, visited)
          ||hasPathCore(matrix, rows, cols, i,     j + 1, str, k + 1, visited))
        {
            return true;
        }
        visited[index] = false;
        return false;
    }
};
*/