#include <iostream>
#include <random>
using namespace std;

// 全局初始化随机数生成器
random_device rd;
mt19937 gen(rd());
// 随机数生成器重复初始化：每次调用 get_random_num 都会重新初始化随机数生成器，这会导致每次生成的随机数相同。应该只初始化一次。
int get_random_num(int min, int max)
{
    uniform_int_distribution<int> dis(min, max);
    int random_num = dis(gen);
    return random_num;
}

int main()
{
    // 生成一个50个名字的数组
    string names[] = {"Landon", "Emmett", "Greyson", "Noah", "Jace", "Jaxton", "Sawyer", "LincoLn",
                      "Isaac", "Asher", "DecLan", "Theo", "Levi", "Dominic", "Austin", "Ethan", "OLiver", "Hudson",
                      "Owen", "Benjamin", "Hiles", "williamJoshua", "Henry", "Lucas", "Alexander", "Jackson", "Hason",
                      "Grayson", "Ryder", "ELijah", "Liam", "Caleb", "Thomas", "Cooper", "Hunter", "Connor"};
    string arr_position[2][2][5];
    int length_names = sizeof(names) / sizeof(names[0]);
    for (int i = 0; i < sizeof(arr_position) / sizeof(arr_position[0]); i++)
    {
        for (int j = 0; j < sizeof(arr_position[0]) / sizeof(arr_position[0][0]); j++)
        {
            for (int k = 0; k < sizeof(arr_position[0][0]) / sizeof(arr_position[0][0][0]); k++)
            {
                string major = i == 0 ? "物理" : "计算机";
                string class_name = j == 0 ? "一班" : "二班";
                int poistion = k + 1;
                string name = names[get_random_num(0, length_names - 1)];
                string msg = major + "专业，" + class_name + "，" + "座位号为 " + to_string(poistion) + "的同学叫：" + name;
                arr_position[i][j][k] = msg;
            }
        }
    }
    cout << "信息准备完成，开始输出：" << endl;
    for (int i = 0; i < sizeof(arr_position) / sizeof(arr_position[0]); i++)
    {
        for (int j = 0; j < sizeof(arr_position[0]) / sizeof(arr_position[0][0]); j++)
        {
            for (int k = 0; k < sizeof(arr_position[0][0]) / sizeof(arr_position[0][0][0]); k++)
            {
                cout << arr_position[i][j][k] << endl;
            }
        }
    }
    return 0;
}
