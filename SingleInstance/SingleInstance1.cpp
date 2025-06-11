#include <iostream>
#include <mutex>
#include <pthread.h>

class SingleInstance
{
    public:
        static SingleInstance *GetInstance();
        static void deleteInstance();

        void Print();
    private:
        SingleInstance();
        ~SingleInstance();

        SingleInstance(const SingleInstance &signal);

    private:
        static SingleInstance *m_SingleInstance;
};

SingleInstance *SingleInstance::m_SingleInstance = NULL;

SingleInstance* SingleInstance :: GetInstance()
{

    if (m_SingleInstance == NULL)
    {
        m_SingleInstance = new (std:: nothrow) SingleInstance;
    }

    return m_SingleInstance;
}

void SingleInstance::deleteInstance()
{

    if (m_SingleInstance)
    {
        delete m_SingleInstance;
        m_SingleInstance = NULL;

    }
}

void SingleInstance::Print()
{

    std::cout <<"我的实例内存地址是"<<this <<std::endl;

}

SingleInstance :: SingleInstance()
{
    std::cout<<"构造函数"<<std::endl;

}

SingleInstance:: ~SingleInstance()
{
    std::cout<<"析构函数"<<std::endl;

}

void *PrintHello(void *threadid)
{
    pthread_detach(pthread_self());

    int tid = *((int*)threadid);

    std::cout<<"hi,我是线程ID： ["<<tid<<"]"<<std::endl;

    SingleInstance::GetInstance()->Print();

    pthread_exit(NULL);
}

#define NUM_THREADS 5

int main(void)
{
    pthread_t threads[NUM_THREADS] = {0};
    int indexes[NUM_THREADS] = {0};

    int ret =0;
    int i=0;

    std ::cout<<"main():开始..."<<std::endl;

    for (int i=0;i<NUM_THREADS;i++)
    {
        std::cout<< "main():创建线程：["<<i<<"]" <<std::endl;

        indexes[i] = i;

        ret = pthread_create(&threads[i],NULL,PrintHello,(void *)&(indexes[i]));
        if(ret)
        {
            std::cout<<"Error:无法创建线程，"<<ret<<std::endl;
            exit(-1);
        } 
    }

    SingleInstance::deleteInstance();
    std ::cout<<"main():结束！"<<std::endl;
    

    std::cin.get();
}
