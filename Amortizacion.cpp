#include<bits/stdc++.h>
using namespace std;

auto getInterest(const double debt,const double interest)->double{
    return debt * interest;
}
auto getRent(const double debt, const double interest, const int year)->double{
    return (debt*interest)/(1-pow((1+interest),(-1)*year));
}
auto getAmortization(const double rent,const double interest)->double{
    return rent - interest;
}
auto getBalance(const double debt,const double input)->double{
    return (debt - input)<0? 0 : debt - input;
}
auto amortizationTable(const double debt, const double interest, const int year)->void{
    if (year == 0) return;
    double rent = getRent(debt,interest,year),inter = getInterest(debt,interest),amortization = getAmortization(rent,inter), balance = getBalance(debt,amortization);
    cout<<year<<"\t"<<rent<<"\t"<<inter<<"\t\t"<<amortization<<"\t\t"<<(int)balance<<endl;
    amortizationTable(balance,interest,year-1);
}
auto main()->int{
    double debt = 0.0, interest = 0.0;
    int years;
    try{
        cout<<"Type the original debt: ";
        cin>>debt;
        cout<<"Type the interest: ";
        cin>>interest;
        cout<<"Type the years: ";
        cin>>years;
        if(debt == 0) throw 1;
        if(interest == 0) throw 2;
        if(interest > 1) throw 4;
        if(years == 0) throw 3;
        cout<<"Period\tRent\tInterest\tAmortization\tBalance"<<endl;
        amortizationTable(debt,interest,years);
    }catch(int error){
        switch(error){
            case 1: cout<<"The debt can not be zero"<<endl; break;
            case 2: cout<<"The interest can not be zero"<<endl; break;
            case 3: cout<<"The years can not be zero"<<endl;
            case 4: cout<<"The interest can not be higher than 1"<<endl; break;
            default: cout<<"Error not handled"<<endl; break;
        }
    }
    return 0;
}