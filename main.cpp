#include <iostream>
#include<stdlib.h>
#include<map>
#include<vector>
using namespace std;

map<string,string>user;
map<string,int>product;

struct cart
{
    string pname;
    int price;
    int quantity;
public:
    cart(string name,int p,int q)
    {
        pname=name;
        price=p;
        quantity=q;
    }

};

void viewCart(vector<cart> &mycart)
    {
        system("CLS");
        cout<<"\n--------------------------MY CART--------------------------"<<endl;
        cout<<"product  "<<"  quantity "<<"  price "<<endl;
        int total=0;
        for(int i=0; i<mycart.size(); i++)
        {

            cout<<mycart[i].pname<<"      "<<mycart[i].quantity<<"       "<<mycart[i].price*mycart[i].quantity<<endl;
            total+= mycart[i].price*mycart[i].quantity;
        }
        cout<<"total price = "<<total;
    }

void buy(vector<cart> &mycart)
{
   viewCart(mycart);
   cout<<"enter card number"<<endl;
   long a;
   cin>>a;
   cout<<"enter cvv"<<endl; int b; cin>>b;
   cout<<"enter otp"<<endl; int c; cin>>c;
   cout<<"enter amount to pay"<< endl; int d; cin>>d;
   cout<<"payment successful!! ";
}
void createaccount(bool &login)
{
  string name,password;
    cout<<"enter username"<<endl;
    cin>>name;
    cout<<"enter password"<<endl;
    cin>>password;
  user[name]=password;
  login=true;
}

bool validateUser(bool &login)
{
    string name,password;
    cout<<"enter username"<<endl;
    cin>>name;
    cout<<"enter password"<<endl;
    cin>>password;

    if(user.find(name)==user.end())
        return false;
        string p=user[name];
    if(p==password)
    {
    login=true;
    return true;
    }
    return false;
}

void menu(bool account)
{
    vector<cart>mycart;
   m: system("cls");
   cout<<"\n--------------------------------SELECT PRODUCT--------------------------------- "<<endl;
   map<string,int> :: iterator i;
   for(i=product.begin();i!=product.end();i++)
    cout<< i->first<<" "<<i->second<<endl;
   cout<<"Enter here   ";
   string name;
   cin>>name;
   if(account==false)
    {
        cout<<"login to continue shopping"<<endl;
    again: cout<<"Enter 0 if already had account else Enter 1 to create account"<<endl;
    int a;
    cin>>a;
    if(a==0)
       {if(! validateUser(account))
        {
            cout<<"invalid username or password TRY AGAIN";
            goto again;
        }
       }
    else
        createaccount(account);
    }
   cout<<"Enter 1 to add to cart"<<endl<<"enter 0 to go to menu"<<endl;
   int a;
   cin>>a;
   if(a==1)
    {
        int q; cout<<"enter quantity  ";
        cin>>q;
        mycart.push_back(cart (name,product[name],q));
    }
    else
        goto m;

    system("CLS");
    cout<<"enter 1 to buy now" <<endl<< "enter 2 to add more items to cart menu" <<endl;
    int b;
    cin>>b;
    if(b==1)
    {
        buy(mycart);
        return;
    }
    else goto m;
}


int main()
{
    product["shirt"]=500;
    product["trouser"]=800;
    product["shoes"]=1000;
    product["bag"]=400;
    product["jean"]=700;
    user["shubham"]="1";
    user["kamal"]="2";
    user["manu"]="3";
    home: system("cls"); cout<<"1. Login"<<endl;
    cout<<"2. Continue as guest"<<endl;
    bool account=false;
   int a;
   cin>>a;

   if(a==1)
    {
    if(!validateUser(account))
        {
        cout<<"invalid username or password"<<endl;
        goto home;
        }
    else
       {
        account =true;
         menu(account);
       }
    }
   else
    menu(account);
        return 0;

}
