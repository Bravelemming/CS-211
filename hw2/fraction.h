/*---------------------
Jack Witherell
fraction.h allows creation
and manipulation of fractions
as a custom data type. allows
initialization and comparison
as well as operations involving
+, -, *, /, <, >, <=, >=, ==, !=

version .95 (not perfect)

recommend viewing in notepad++ or vim
finished sept 4 2014
instructor dharden cs11
---------------------*/

#ifndef FRACTION_H
#define FRACTION_H

#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;
class fraction{
    public:
    //Initializer
        fraction(int numero=0, int denomo=1);
    //Fraction/Fraction comparison
        fraction operator<(const fraction& other) const;
        fraction operator<=(const fraction& other) const;
        fraction operator>(const fraction& other) const;
        fraction operator>=(const fraction& other) const;
        fraction operator==(const fraction& other) const;
        fraction operator!=(const fraction& other) const;
    //Fraction/Interger comparison
        friend fraction operator<(const int& other, const fraction& frac);
        friend fraction operator<=(const int& other, const fraction& frac);
        friend fraction operator>(const int& other, const fraction& frac);
        friend fraction operator>=(const int& other, const fraction& frac);
        friend fraction operator<(const fraction& frac, const int& other);
        friend fraction operator<=(const fraction& frac, const int& other);
        friend fraction operator>(const fraction& frac, const int& other);
        friend fraction operator>=(const fraction& frac, const int& other);
        friend fraction operator==(int& a, const fraction& other);
        friend fraction operator!=(int& a, const fraction& other);
    //Fraction/Fraction operations
        fraction operator+(const fraction& other) const;
        fraction operator-(const fraction& other) const;
        fraction operator*(const fraction& other) const;
        fraction operator/(const fraction& other) const;
    //Fraction/Interger operations
        friend fraction operator+(int& a, const fraction& other);
        friend fraction operator-(int& a, const fraction& other);
        friend fraction operator-(const fraction& other, int& a);
        friend fraction operator*(int& a, const fraction& other);
        friend fraction operator/(int& a, const fraction& other);
        friend fraction operator/(const fraction& other, int& a);
    //Fraction/Fraction arith
        fraction operator+=(fraction& other);
        fraction operator-=(fraction& other);
        fraction operator*=(fraction& other);
        fraction operator/=(fraction& other);
    //Fraction/Interger arith
        friend fraction operator+=(fraction& other, int& a);
        friend fraction operator-=(fraction& other, int& a);
        friend fraction operator*=(fraction& other, int& a);
        friend fraction operator/=(fraction& other, int& a);
    //Fraction increment, decrement
        fraction operator++();
        fraction operator--();
        fraction operator++(int);
        fraction operator--(int);
    //Output to stream
        friend ostream& operator<<(ostream& os, const fraction& ft);
    //Input from file
        friend istream& operator>>(istream &in, fraction& ft);
    private:
        int numer;
        int denom;
    //Reduce Function
        void reduce();
};



//fraction takein, storing, and reduction
fraction::fraction(int numero, int denomo){
    numer=numero;
    denom=denomo;
//if fraction is equal to zero, make it a whole number equal to zero
    if (numer==0){
        denom=1;
    }
    reduce();
}
void fraction::reduce(){
//if both fraction is positive, and lcd found, reduce.
    if (((numer>=0)&&(denom>=0))||((numer<=0)&&(denom<=0))){
        for (int i = numer*denom; i > 1; i--){
            if (((numer>=0)&&(denom>=0))||((numer<=0)&&(denom<=0))){
                if ((denom%i ==0) && (numer %i ==0)){
                    denom /= i;
                    numer /= i;
                }
            }
        }
    }
//if fraction is negative due to numerator, find lcd and reduce, keep negative
    if (numer<0){
        for (int i = (0-numer)*denom; i > 1; i--){
            if ((denom%i ==0) && ((0-numer) %i ==0)){
                denom /= i;
                numer /= i;
            }
        }
    }
//if fraction is negative due to denominator, find lcd and reduce, keep negative
    if (denom<0){
        for (int i = numer*(0-denom); i > 1; i--){
            if (((0-denom) %i ==0) && (numer %i ==0)){
                denom /= i;
                numer /= i;
            }
        }
    }
//if both are negative, make positive (since it's a positive fraction
    if ((numer<0)&&(denom<0)){
        numer=abs(numer);
        denom=abs(denom);
    }
}

//Frac compare Frac overloads

fraction fraction::operator<(const fraction& other) const{
    if((float(numer)/float(denom))<(float(other.numer)/float(other.denom))){
        return 1;}
    else{return 0;}
}
fraction fraction::operator<=(const fraction& other) const{
    if((float(numer)/float(denom))<=(float(other.numer)/float(other.denom))){
        return 1;}
    else{return 0;}
}
fraction fraction::operator>(const fraction& other) const{
    if((float(numer)/float(denom))>(float(other.numer)/float(other.denom))){
        return 1;}
    else{return 0;}
}
fraction fraction::operator>=(const fraction& other) const{
    if((float(numer)/float(denom))>=(float(other.numer)/float(other.denom))){
        return 1;}
    else{return 0;}
}
fraction fraction::operator==(const fraction& other) const{
    if((float(numer)/float(denom))==(float(other.numer)/float(other.denom))){
        return 1;}
    else{return 0;}
}
fraction fraction::operator!=(const fraction& other) const{
    if((float(numer)/float(denom))!=(float(other.numer)/float(other.denom))){
        return 1;}
    else{return 0;}
}

//Frac compare int overloads

fraction operator<(const int& other, const fraction& frac){
    if((float(frac.numer)/float(frac.denom))<float(other)){
        return 0;}
    else{return 1;}
}
fraction operator<=(const int& other, const fraction& frac){
    if((float(frac.numer)/float(frac.denom))<=float(other)){
        return 0;}
    else{return 1;}
}
fraction operator>(const int& other, const fraction& frac){
    if((float(frac.numer)/float(frac.denom))>float(other)){
        return 0;}
    else{return 1;}
}
fraction operator>=(const int& other, const fraction& frac){
    if((float(frac.numer)/float(frac.denom))>=float(other)){
        return 0;}
    else{return 1;}
}
fraction operator<(const fraction& frac, const int& other){
    if((float(frac.numer)/float(frac.denom))<float(other)){
        return 1;}
    else{return 0;}
}
fraction operator<=(const fraction& frac, const int& other){
    if((float(frac.numer)/float(frac.denom))<=float(other)){
        return 1;}
    else{return 0;}
}
fraction operator>(const fraction& frac, const int& other){
    if((float(frac.numer)/float(frac.denom))>float(other)){
        return 1;}
    else{return 0;}
}
fraction operator>=(const fraction& frac, const int& other){
    if((float(frac.numer)/float(frac.denom))>=float(other)){
        return 1;}
    else{return 0;}
}

fraction operator==(int& a, const fraction& other){
    if((float(other.numer)/float(other.denom))==(float(a))){
        return 1;}
    else{return 0;}
}
fraction operator!=(int& a, const fraction& other){
    if((float(other.numer)/float(other.denom))==(float(a))){
        return 0;}
    else{return 1;}
}

//frac operator frac overloads

fraction fraction::operator+(const fraction& other) const{
    fraction ans;
    ans.numer=((other.denom*numer)+(denom*other.numer));
    ans.denom=denom*other.denom;
    ans.reduce();
    return ans;
}
fraction fraction::operator-(const fraction& other) const{
    fraction ans;
    ans.numer=((other.denom*numer)-(denom*other.numer));
    ans.denom=denom*other.denom;
    ans.reduce();
    return ans;
}
fraction fraction::operator*(const fraction& other) const{
    fraction ans;
    ans.numer=(numer*other.numer);
    ans.denom=(denom*other.denom);
    ans.reduce();
    return ans;
}
fraction fraction::operator/(const fraction& other) const{
    fraction ans;
    ans.numer=(numer*other.denom);
    ans.denom=(denom*other.numer);
    ans.reduce();
    return ans;
}

//frac operator int overloads

fraction operator+(int& a, const fraction& other){
    fraction ans;
    ans.numer=(other.numer+(other.denom*a));
    ans.denom=other.denom;
    ans.reduce();
    return ans;
}
fraction operator-(int& a, const fraction& other){
    fraction ans;
    ans.numer=((other.denom*a)-other.numer);
    ans.denom=other.denom;
    ans.reduce();
    return ans;
}
fraction operator-(const fraction& other, int& a){
    fraction ans;
    ans.numer=(other.numer-(other.denom*a));
    ans.denom=other.denom;
    ans.reduce();
    return ans;
}
fraction operator*(int& a, const fraction& other){
    fraction ans;
    ans.numer=(other.numer*a);
    ans.denom=(other.denom);
    ans.reduce();
    return ans;
}
fraction operator/(int& a, const fraction& other){
    fraction ans;
    ans.numer=(a*other.denom);
    ans.denom=(other.numer);
    ans.reduce();
    return ans;
}
fraction operator/(const fraction& other, int& a){
    fraction ans;
    ans.numer=(other.numer);
    ans.denom=(other.denom*a);
    ans.reduce();
    return ans;
}

//frac frac shorthand and frac int shorthand

fraction fraction::operator+=(fraction& other){
    fraction ans;
    ans.numer=((other.denom*numer)+(denom*other.numer));
    ans.denom=denom*other.denom;
    numer=ans.numer;
    denom=ans.denom;
    ans.reduce();
    reduce();
    return ans;
}
fraction fraction::operator-=(fraction& other){
    fraction ans;
    ans.numer=((other.denom*numer)-(denom*other.numer));
    ans.denom=denom*other.denom;
    numer=ans.numer;
    denom=ans.denom;
    ans.reduce();
    reduce();
    return ans;
}
fraction fraction::operator*=(fraction& other){
    fraction ans;
    ans.numer=numer*other.numer;
    ans.denom=denom*other.denom;
    numer=ans.numer;
    denom=ans.denom;
    ans.reduce();
    reduce();
    return ans;
}
fraction fraction::operator/=(fraction& other){
    fraction ans;
    ans.numer=numer*other.denom;
    ans.denom=denom*other.numer;
    numer=ans.numer;
    denom=ans.denom;
    ans.reduce();
    reduce();
    return ans;
}
fraction operator+=(fraction& other, int& a){
    other.numer=(other.numer+(other.denom*a));
    return other;
}
fraction operator-=(fraction& other, int& a){
    other.numer=(other.numer-(other.denom*a));
    return other;
}
fraction operator*=(fraction& other, int& a){
    other.numer=(other.numer*a);
    other.reduce();
    return other;
}
fraction operator/=(fraction& other, int& a){
    other.denom=(other.denom*a);
    other.reduce();
    return other;
}

//frac increment decrement

fraction fraction::operator++(){
    numer=int(numer+abs(denom));
    fraction f(numer,denom);
    f.reduce();
    return f;
}
fraction fraction::operator--(){
    numer=int(numer-abs(denom));
    fraction f(numer,denom);
    f.reduce();
    return f;
}
fraction fraction::operator++(int){
    fraction f(numer,denom);
    numer=int(numer+abs(denom));
    f.reduce();
    return f;
}
fraction fraction::operator--(int){
    fraction f(numer,denom);
    numer=int(numer-abs(denom));
    f.reduce();
    return f;
}

//ostream, works perfectly! takes in fraction and outputs it into correct format
ostream& operator<<(ostream& os, const fraction& ft){
    if (ft.numer<0||ft.denom<0){
        os <<"-";
    }
    if (ft.denom==1){
        os<<abs(ft.numer);
    }
    else{
        if (abs(ft.numer)>abs(ft.denom)){
            if((ft.numer%ft.denom)!=0){
                os <<abs(ft.numer/ft.denom)<<"+"<<abs(ft.numer%ft.denom)<<"/"<<abs(ft.denom);
            }
            else{
                os <<abs(ft.numer/ft.denom);
            }
        }
        else{
            os <<abs(ft.numer)<<"/"<<abs(ft.denom);
        }
    }
    return os;
}

//istream, takes in a string form fraction and uses substring to parse it, atoi to turn it into an interger
istream& operator>>(istream &in, fraction& ft){
    ft.numer=3;
    ft.denom=5;
    string s;
    in>>s;
    size_t plu = s.find("+");
    size_t sla = s.find("/");
    size_t len = s.length();
    size_t neg = s.find("-");
    string plusec;
    string num;
    string den;
    int plupl;
    int numnu;
    int dende;
    if (neg!=0){
        if (plu>20){
            if (sla>30){
                num=s.substr(0,len);
                ft.numer=atoi(num.c_str());
                ft.denom=1;
            }
            else{
                num=s.substr(0,sla);
                den=s.substr(sla+1,len-sla+1);
                ft.numer=atoi(num.c_str());
                ft.denom=atoi(den.c_str());
            }
        }
        else{
            plusec=s.substr(0,plu);
            num=s.substr(plu+1,sla-plu-1);
            den=s.substr(sla+1,len-sla+1);
            plupl=atoi(plusec.c_str());
            numnu=atoi(num.c_str());
            dende=atoi(den.c_str());
            ft.numer=((plupl*dende)+numnu);
            ft.denom=dende;
        }
    }
    else{
        if (plu>20){
            if (sla>30){
                num=s.substr(1,len-1);
                ft.numer=atoi(num.c_str());
                ft.denom=1;
            }
            else{
                num=s.substr(1,sla-1);
                den=s.substr(sla+1,len-sla+1);
                ft.numer=atoi(num.c_str());
                ft.denom=atoi(den.c_str());
            }
        }
        else{
            plusec=s.substr(1,plu-1);
            num=s.substr(plu+1,sla-plu-1);
            den=s.substr(sla+1,len-sla+1);
            plupl=atoi(plusec.c_str());
            numnu=atoi(num.c_str());
            dende=atoi(den.c_str());
            ft.numer=((plupl*dende)+numnu);
            ft.denom=dende;
        }
        ft.numer=0-ft.numer;
    }
    ft.reduce();
    return in;
}

#endif