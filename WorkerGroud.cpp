#include <iostream>
#include <vector>
#include <map>
#include <ctime>

#define CEHUA   0
#define MEISHU  1
#define YANFA   2

using namespace std;

class Worker
{
public:
    Worker(string name, int salary)
    {
        this->m_Name = name;
        this->m_Salary = salary;
    }

    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker> &workers)
{
    string nameSeed = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++)
    {
        string name = "员工";
        name += nameSeed[i];
        int salary = rand() % 10000 + 10000;
        Worker wk(name, salary);
        workers.push_back(wk);
    }
}

void workerByGroud(vector<Worker> &workers, multimap<int, Worker> &mp)
{
    for(int i = 0; i < 10; i++)
    {
        // 随机分组
        int groud = rand() % 3;
        mp.insert(make_pair(groud, workers[i]));
    }
}

void printWorkersByGroud(const multimap<int, Worker> &mp)
{
    // 策划
    cout << "策划组：" << endl;
    multimap<int, Worker>::const_iterator first = mp.find(CEHUA);
    int num = mp.count(CEHUA);
    int index = 0;
    for(; index < num; first++, index++)
    {
        cout << "姓名:" << first->second.m_Name << "\t薪资:" << first->second.m_Salary << endl;
    }
    cout << "-------------" << endl;
    // 美术组
    cout << "美术组：" << endl;
    first = mp.find(MEISHU);
    num = mp.count(MEISHU);
    index = 0;
    for(; index < num; first++, index++)
    {
        cout << "姓名:" << first->second.m_Name << "\t薪资:" << first->second.m_Salary << endl;
    }
    cout << "-------------" << endl;

    // 研发组
    cout << "研发组：" << endl;
    first = mp.find(YANFA);
    num = mp.count(YANFA);
    index = 0;
    for(; index < num; first++, index++)
    {
        cout << "姓名:" << first->second.m_Name << "\t薪资:" << first->second.m_Salary << endl;
    }
    cout << "-------------" << endl;    
}


int main(void)
{
    srand((unsigned int)time(NULL));
    vector<Worker> workers;
    // 创建员工
    createWorker(workers);
    // 员工分组
    multimap<int, Worker> mp;
    workerByGroud(workers, mp);
    printWorkersByGroud(mp);
    return 0;
}