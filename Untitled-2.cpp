#include <iostream>
using namespace std;

int main()
{
    // 读入场地大小
    int n, m;
    cin >> n >> m;
    // 创建一个二维数组，用0表示没有染色，用1表示染上洋红蒸汽，用2表示染上纯白水汽
    int field[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            field[i][j] = 0;
        }
    }
    // 读入回合数
    int q;
    cin >> q;
    // 对每个回合进行处理
    for (int k = 0; k < q; k++)
    {
        // 读入当前回合的类型和参数
        int t, x, y;
        cin >> t >> x >> y;
        // 如果是羊之主的回合
        if (t == 1)
        {
            // 如果选择了某一行
            if (x == 1)
            {
                // 将该行所有地块染上洋红蒸汽
                for (int j = 0; j < m; j++)
                {
                    field[y - 1][j] = 1;
                }
            }
            // 如果选择了某一列
            else
            {
                // 将该列所有地块染上洋红蒸汽
                for (int i = 0; i < n; i++)
                {
                    field[i][y - 1] = 1;
                }
            }
        }
        // 如果是agKc的回合
        else
        {
            // 将本格和其上下左右各一格染上纯白水汽，注意不能超出场地边界
            field[x - 1][y - 1] = 2;
            if (x - 2 >= 0)
                field[x - 2][y - 1] = 2;
            if (x < n)
                field[x][y - 1] = 2;
            if (y - 2 >= 0)
                field[x - 1][y - 2] = 2;
            if (y < m)
                field[x - 1][y] = 2;
        }
    }
    // 统计染上纯白水汽的地块数量
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 2)
                count++;
        }
    }
    // 输出结果
    cout << count << endl;
    return 0;
}
