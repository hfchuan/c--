#include <iostream >



class Single 
{
    public:
        static Single &GetInstance();

        void Print();

    private:
        Single();
        ~Single();

        Single(const Single &signal);
        const Single &operator =(const Single &signal);

    

};

Single &Single ::GetInstance()
{
    static Single signal;
    return signal;

}

void Single::Print()
{

    std::cout<<"我的实例内存地址是："<<this <<std::endl;

}

Single::Single()
{
    std::cout<<"构造函数"<<std::endl;

}

Single::~Single()
{
    std::cout<<"析构函数"<<std::endl;

}

int main()
{

    std::cin.get();
} 