#include <bits/stdc++.h>
using namespace std;

struct T_icket
{
    int SrNo;
    string movie;
    string name;
    string mobNo;
    int slot;
    int pincode;
    int sbp[4],sbg[4];
     T_icket *next=NULL;
};

struct node{
   int key;
   struct node *left, *right;
};
struct theatre
{
    char arr[9][11];
    int Arr[10];
    int m_ovie;
    int s_lot;
    theatre *next;
};

class Movie
{

    public:
        T_icket *h=NULL;
        theatre *head=NULL;
        int  g,tn=11;
        int a,b,x0,x1,x2,x3,x4;
        int row[4],G[4], col[4];
        int ar;
        void home();
        int disp();
        int ticket();
        void ad();
        void price();
        void show();
        void print_time();
        void seat_matrix(int x1,int x2,int ar,int x0);
        void insertticket(int sn,string m,string n,string mn,int s,int p,int sbp_d[4],int sbg_d[4]);
};

class Ticket : public Movie
{

public:
    string l,mbno;
    int timings();
    int membership(int total);
    int num_ticket();
    int seat();
    int total_cost(int x1, int x2);
    int area();
    void details();
    void display(int x1,int x4,int a,int x0,int ar,int x2, int row[4], int col[4], int G[4],int g);
};

class String
{
public:
    node* binarytree(node* root,int key);
    node* newNode(int item);
    node* insert(node* node,int key);
    void traversetree(node *root);
};

void Movie::home()
{
    int c1,x=1;
    Ticket t;
    g=7890012;
    fstream file;
     file.open("C:\\Users\\user\\Desktop\\e1.xls",ios::app);
    if(file)
    {
        file<<"\n\t"<<"Ref Id.\tMovie\tSlot\tName\tContact No\tPin-code\tSeats Booked" ;
    }
    file.close();

while(x==1)
{
    cout<<"\n\t\t\t ----------------------------------";
    cout<<"\n\t\t\t Online Movie Ticket Booking System";
    cout<<"\n\t\t\t ----------------------------------";
    cout<<"\n\t\t\t\t IT's SHOWTIME!";
    cout<<"\n\n\t\t\t\t Press 1. To Book a Ticket.";
    cout<<"\n\t\t\t\t Press 2. To know the show timings.";
    cout<<"\n\t\t\t\t Press 3. To know the ticket price.";
    cout<<"\n\t\t\t\t Press 4. To Cancel the ticket.";
    cout<<"\n\t\t\t\t Press 5. To know more about advertising in our theatre. ";
    cout<<"\n\t\t\t\t Press 6. To get the membership card and enjoy amazing benefits. ";
    cout<<"\n\t\t\t\t Press 7. To Exit. \n\n";

    cout<<"\t\t\t\t Enter Your Choice : ";
    cin>>c1;

    switch(c1)
    {
    case 1:
        {
            ticket();
            x=disp();
            g++;
            break;
        }
    case 2:
        {
            print_time();
            x=disp();
            break;
        }
    case 3:
        {
            price();
            x=disp();
            break;
        }
    case 4:
        {
            cout<<"\n\t\t\t\tThe site is under construction.Sorry for the inconvinence caused.Please approach the theatres to cancel the ticket.";
            x=disp();
            break;
        }
    case 5:
        {
            cout<<"\n\t\t\t\t We do advertise in our theatres. Please call 9456881270 for more information.";
            x=disp();
            break;
        }
    case 6:
        {
            cout<<"\n\t\t\t\t Enjoy 10% discount on ticket price whenever you book your tickets.";
            cout<<"\n\n\t\t\t\t Do you want Membership card? (Y/N) ";
            char o;
            cin>>o;
            if(o=='Y')
            {
                t.details();
            }
            x=disp();
            break;
        }
    case 7:
        {
            exit(0);
            break;
        }
    default:
        {
            cout<<"INVALID CHOICE. "<<endl;
            break;
        }
    }
}

}

int Movie::disp()
{
    cout<<"\n\t\t\t\t Do you want to go back to HomeScreen: (Y/N) ";
    char ans;
    cin>>ans;
    if(ans=='Y' || ans=='y')
        return 1;
    else
        return 0;
}

int Movie::ticket()
{

    Ticket t;
    cout<<"\n\t\t\t\t Please enter the code of movie you want to watch.";
    cout<<"\n\t\t\t\t Enter 1. Avengers";
    cout<<"\n\t\t\t\t Enter 2. Spiderman";
    cout<<"\n\t\t\t\t Enter 3. Deadpool";
    cout<<"\n\t\t\t\t Enter 4. Iron Man";
    cout<<"\n\t\t\t\t Enter 5. Godzilla \n";
    cout<<"\n\n\t\t\t\t Please select your movie: ";
    cin>>a;
    x0=t.timings();
    x1=t.num_ticket();
    x2=t.seat();
    x3=t.total_cost(x1,x2);
    x4=t.membership(x3);
    seat_matrix(x1,x2,a,x0);
    ar=t.area();
    t.details();
    t.display(x1,x4,a,x0,ar,x2,row,col,G,g);
    return a;
}

void Movie::price()
{

    cout<<"\n\n\t\t\t\t Please select PREMIUM or GOLD seats. (P/G) ";
    cout<<"\n\t\t\t\t Premium = Rs. 150 \n\t\t\t\t Gold = Rs. 300  ";
}

void Movie::print_time()
{

    cout<<"\n\t\t\t\t Timings available for the show are: ";
    cout<<"\n\t\t\t\t 1. 0800";
    cout<<"\n\t\t\t\t 2. 1300";
    cout<<"\n\t\t\t\t 3. 1450";
    cout<<"\n\t\t\t\t 4. 1800";
    cout<<"\n\t\t\t\t 5. 2100";
    cout<<"\n\t\t\t\t 6. 2230";
    cout<<"\n\t\t\t\t 7. 2300";
    cout<<"\n\t\t\t\t 8. 0100 \n";
}

int Ticket::total_cost(int x1,int x2)
{
    if(x2==1)
        return x1*150;
    if(x2==-1)
        return x1*300;
}

int Ticket::membership(int total)
{

    int y;
    cout<<"\n\t\t\t\t Do you have membership card? (Y/N) ";
    char ans;
    cin>>ans;
    if(ans=='Y' || ans =='y')
    {
        y=0.9*total;
    }
    else if(ans=='N' || ans=='n')
    {
        y=total;
    }
    else{
        cout<<"\n\t\t\t\t Invalid Choice.";
    }
    cout<<"\n\t\t\t\t Your total expense is: "<<y<<"\n";
    return y;
}

int Ticket::seat()
{
    price();
   char ans;
   cin>>ans;
   if(ans=='P')
   {
       cout<<"\n\t\t\t\t You have selected Premium seats.\n";
       return 1;
   }
   else if(ans=='G')
   {
       cout<<"\n\t\t\t\t You have selected Gold seats.\n";
       return -1;
   }
   else
   {
       cout<<"\n\t\t\t\t Invalid choice.";
       seat();
   }
}
int Ticket::num_ticket()
{
    int a1;
    cout<<"\n\n\t\t\t\t Please enter the number of tickets you want: ";
    cin>>a1;
    if(a1>=5)
    {
        cout<<"\n\t\t\t\t You are allowed to book only 4 tickets at a time.";
        num_ticket();
    }
    return a1;
}

int Ticket::timings()
{
    print_time();
    cout<<"\n\t\t\t\t Enter the slot number you want to book: ";
    cin>>b;
    switch(b)
    {
    case 1:
        cout<<"\n\t\t\t\t Available.";
        break;
    case 2:
        cout<<"\n\t\t\t\t Available.";
        break;
    case 3:
        {
            cout<<"\n\t\t\t\t HOUSEFULL! You will have to try again!";
            cout<<"\n\t\t\t\t Do you want to select another slot? (y/n) ";
            char ans;
            cin>>ans;
            if(ans=='y' || ans=='Y')
                {
                    timings();
                }
            else
                {
                    exit(0);
                }
        break;
        }
    case 4:
        cout<<"\n\t\t\t\t Available.";
        break;
    case 5:
        cout<<"\n\t\t\t\t Available.";
        break;
    case 6:
        {
            cout<<"\n\t\t\t\t HOUSEFULL! You will have to try again!";
            cout<<"\n\t\t\t\t Do you want to select another slot? (y/n) ";
            char ans;
            cin>>ans;
            if(ans=='y' || ans=='Y')
                {
                    timings();
                }
            else
                {
                    exit(0);
                }
        break;
        }
    case 7:
        cout<<"\n\t\t\t\t Available.";
        break;
    case 8:
        cout<<"\n\t\t\t\t Available.";
        break;
    default:
        {
            cout<<"\n\t\t\t\t INVALID CHOICE. Try again";
            cout<<"\n\t\t\t\t Do you want to select another slot? (y/n) ";
            char ans;
            cin>>ans;
            if(ans=='y' || ans=='Y')
            {
                timings();
            }
            else
            {
                exit(0);
            }
        }

    }
    return b;
}

int Ticket::area()
{

    String s;
    struct node *root = NULL;
   root = s.insert(root, 395009);
   s.insert(root, 395007);
   s.insert(root, 395001);
   s.insert(root, 395006);
   s.insert(root, 320008);
   s.insert(root, 380004);
   s.insert(root, 382220);
   s.insert(root, 380009);
   s.insert(root, 364001);
   s.insert(root, 364002);
   s.insert(root, 230532);
   s.insert(root, 400001);
   s.insert(root, 400053);
   s.insert(root, 400091);
   s.insert(root, 110008);
   s.insert(root, 110001);
   s.insert(root, 110015);
   s.insert(root, 110060);
   s.insert(root, 560002);
   s.insert(root, 560001);

    cout<<"\n\n\t\t\t\t Enter the pin code of the area where you live.\t";
    cin>>ar;
    if(s.binarytree(root , ar))
      cout<<"\n\t\t\t\t Available";
   else
   {
      cout<<"\n\t\t\t\t Sorry! You will have to try another place.";
      s.traversetree(root);
      cout<<"\n\t\t\t\t Do you want to select another slot? (y/n) ";
      char ans;
      cin>>ans;
      if(ans=='y' || ans=='Y')
      {
          area();
      }
      else
      {
          exit(0);
      }
   }
    return ar;

}

void Movie::seat_matrix(int x1,int x2,int m,int s)
{

     theatre *t,*z,*x;
    t=head;
        while(t!=NULL)
        {
            x=t;
            if(t->m_ovie==m && t->s_lot==s)
                break;
            t=t->next;
        }
        if(t==NULL)
        {
            z=new theatre;
            z->m_ovie=m;
            z->s_lot=s;
            //initialisation of z
            for(int i=0;i<9;i++)
            {
                z->arr[i][0]=i+1+'0';
                for(int j=1;j<11;j++)
                {
                    z->arr[i][j]='A'+j-1;
                }
            }
            z->arr[2][2]=z->arr[4][4]=z->arr[5][8]=z->arr[6][2]=z->arr[6][3]=z->arr[8][4]=z->arr[8][7]=z->arr[9][2]=z->arr[9][3]=z->arr[9][4]=z->arr[9][5]='0';



            for(int i=0;i<10;i++)
            {
                z->Arr[i]=i+1;
            }
            z->Arr[3]=z->Arr[4]=0;

            //insertion of z;
             if(head==NULL)
            {
                head=z;
                t=head;
            }
            else
            {

                x->next=z;
                t=x->next;

            }
        }

    for(int i=0;i<4;i++)
    {
        row[i]=-1;
        col[i]=-1;
        G[i]=-1;
    }

    cout<<"\n\t\t\t\t ------------------------------------- ";
    cout<<"\n\n\t\t\t\t ^    ^    ^    ^    ^    ^    ^    ^";
    cout<<"\n\t\t\t\t |    |    |    |    |    |    |    |";
    cout<<"\n\n\t\t\t\t SCREEN THIS SIDE \n\n\t\t\t\t";
    if(x2==1)
    {

    for(int i=0;i<9;i++){
		for(int j=0;j<11;j++){
			cout<<t->arr[i][j]<<"  ";
		}cout<<"\n\t\t\t\t";
	}
	cout<<"\n\n\t\t\t\t Seats marked 0 are booked. Please enter the seat number (eg. row :1 col: A) you wish to book ";

	for(int i=0;i<x1;i++)
    {
        int j,k;char a;
        cout<<"\n\t\t\t\t Row : ";
        cin>>row[i];
        j=row[i]-1;
        cout<<"\n\t\t\t\t Col : ";
        cin>>a;
        col[i]=a;
        k=a-65+1;



        if(row[i]>9 || row[i]<1 || col[i]>76 || col[i]<65 || t->arr[j][k] == '0')
        {
            cout<<"\n\t\t\t\t Invalid Seat Number.Please Enter Again."<<endl;
            i--;
        }
        else
            {t->arr[j][k]='0';
            cout<<"\n\t\t\t\t-----------"<<endl;}
    }
	cout<<"\n\t\t\t\t Successful! ";

    }
    if(x2==-1)
    {

        cout<<"\n\t\t\t\t  ";
        for(int i=0;i<10;i++)
        {
            cout<<" "<<t->Arr[i];
        }
        cout<<"\n\n\t\t\t\t Seats not marked are booked. Please enter the seat number you wish to book ";
        for(int i=0;i<x1;i++)
        {
            cout<<"\n\t\t\t\t Please enter : ";
            int x_1;
            cin>>x_1;
            if(x_1>10 || x_1<1 || t->Arr[x_1-1]==0)
            {

                cout<<"\n\t\t\t\t Invalid seat number.";
                cout<<"\n\t\t\t\t Enter again: ";
                i--;
            }
            else
            {
                t->Arr[x_1-1]=0;
                G[i]=x_1;
            }
            cout<<"\n\t\t\t\t-----------"<<endl;
        }
	cout<<"\n\t\t\t\t Successful! ";
    }


}

void Ticket::display(int x1,int x4,int a,int x0,int ar,int x2, int row[4], int col[4], int G[4],int g)
{
    time_t t = time(NULL);
    tm* tp = localtime(&t);
    int sbp_d[4],sbg_d[4];
    string w,p;
    if(a==1)
        {p="Avengers";
        w="Screen 1";}
    else if(a==2)
        {p="SpiderMan";
        w="Screen 2";}
    else if(a==3)
        {p="DeadPool";
        w="Screen 3";}
    else if(a==4)
        {p="Iron Man";
        w="Screen 4";}
    else
        {p="Godzilla";
        w="Screen 5";}

    string q;
    if(x0==1)
        q="0080";
    else if(x0==2)
        q="1300";
    else if(x0==4)
        q="1800";
    else if(x0==5)
        q="2100";
    else if(x0==7)
        q="2300";
    else
        {q="0100";}

        string z;
        if(ar==364001)
            z="Gogha Circle, Bhavnagar";
        else if(ar==364002)
            z="Kalvibid, Bhavnagar";
        else if(ar==395009)
            z="Adajan, Surat";
        else if(ar==395001)
            z="City Light, Surat";
        else if(ar==395007)
            z="Vesu,Surat";
        else if(ar==395006)
            z="Varacha, Surat";
        else if(ar==320008)
            z="Maninagar, Ahemdabad";
        else if(ar==380004)
            z="Delhi Gate, Ahemdabad";
        else if(ar==382220)
            z="Adroda, Ahemdabad";
        else if(ar==380009)
            z="Ashram Road, Ahemdabad";
        else if(ar==230532)
            z="Kalbadevi, Mumbai";
        else if(ar==400001)
            z="Bazargate, Mumbai";
        else if(ar==400053)
            z="Andheri, Mumbai";
        else if(ar==400091)
            z="Borivali, Mumbai";
        else if(ar==110008)
            z="Patel Nagar, Delhi";
        else if(ar==110001)
            z="Rajeev Chowk, Delhi";
        else if(ar==110015)
            z="MotiNagar, Delhi";
        else if(ar==110060)
            z="Rajendra Place, Delhi";
        else if(ar==560002)
            z="Bangalore City, Bangalore";
        else if(ar==560001)
            z="Rajbhavan, Bangalore";



    cout<<"\n\n\t\t\t\t----------------Ticket-----------------\n";
    cout<<"\n\t\t\t\t TICKET ";
    cout<<" \n\t\t\t\tCurrent time: "<<tp->tm_hour<<":"<<tp->tm_min<<":"<<tp->tm_sec;
    cout <<" \n\t\t\t\tCurrent Date: " << tp->tm_mday<<"\/"<< tp->tm_mon + 1<<"\/"<< tp->tm_year + 1900 << endl;
    cout<<"\n\n\t\t\t\t Reference Id: "<<g;
    cout<<"\n\n\t\t\t\t Movie: "<<p;
    cout<<"\n\t\t\t\t Timings: "<<q<<" hours ";
    cout<<"\n\t\t\t\t "<<w;
    cout<<"\n\t\t\t\t PinCode: "<<ar;
    cout<<"\n\t\t\t\t Area: "<<z;
    cout<<"\n\t\t\t\t Total amount paid = "<<x4;
    cout<<"\n\t\t\t\t Number of Seats booked = "<<x1;
    cout<<"\n\t\t\t\t Seats Booked is/are : ";
    if(x2==1)
    {
        for(int i=0;row[i]!=-1;i++)
        {
            char a=col[i];
            cout<<row[i];
            cout<<a;
            cout<<" ";
            sbp_d[i]=(row[i]-1)*10+a-65+1;
        }
    }
    if(x2==-1)
    {
        for(int i=0;G[i]!=-1;i++)
        {
            cout<<G[i]<<" ";
            sbg_d[i]=G[i]-1;
        }

    }
    cout<<"\n\n\t\t\t\t----------------------------------------\n";
    insertticket(g,p,l,mbno,x0,ar,sbp_d,sbg_d);

 fstream file;
  file.open("C:\\Users\\user\\Desktop\\e1.xls",ios::app);
     //char m1[120]="Ref Id.\tMovie\tSlot\tName\tContact No\tPin-code\tNo ofSeats Booked";
    if(file)
    {
        file<<"\n\t"<<g<<"\t"<<p<<"\t"<<x0<<"\t"<<l<<"\t"<<mbno<<"\t"<<ar<<"\t"<<x1;
    }
    file.close();
}

void Ticket::details()
{

    int q;getchar();
    cout<<"\n\t\t\t\t Enter your Name: ";
    //string l;
    getline(cin,l);
    cout<<"\n\t\t\t\t Enter your Contact No. ";
    //string mbno;
    getline(cin,mbno);
    //for(int i=0;i<10;i++)
        //{cin>>m[i];}
    cout<<"\n\t\t\t\t Select the method of payment. ";
    cout<<"\n\t\t\t\t 1. Credit/Debit Card \t 2. UPI \t 3. Payment in person ";
    cin>>q;
    if(q==1)
    {
        cout<<"\n\t\t\t\t Enter your card number: ";
        long long int r;
            cin>>r;
        cout<<"\n\t\t\t\t Enter the Name on Card: ";
        string k;getchar();
        getline(cin,k);
        cout<<"\n\t\t\t\t Enter year of expiry: ";
        int p;
        cin>>p;
        if(p<2021)
        {
            cout<<"\n\t\t\t\t Card expired!";
            details();
        }
        cout<<"\n\t\t\t\t Enter month of expiry: ";
        int z;
        cin>>z;
        if(p==2021)
        {
        if(z<6)
        {
            cout<<"\n\t\t\t\t Card expired!";
            details();
        }
        }
        cout<<"\n\t\t\t\t Enter CVV: ";
        int n;
        cin>>n;
        cout<<"\n\n\n\t\t\t\t Please wait while your payment is processed!";
        cout<<"\n\n\n\t\t\t\t Payment Successful!";
        cout<<"\n\t\t\t\t Thank you!";
    }
    if(q==2)
    {
        cout<<"\n\t\t\t\t Please enter your UPI Id ";
        string k;
        cin>>k;
        cout<<"\n\t\t\t\t Please approve the payment from your mobile. ";
        cout<<"\n\n\n\t\t\t\t Please wait while your payement is processed!";
        cout<<"\n\n\n\t\t\t\t Payment Successful!";
        cout<<"\n\t\t\t\t Thank you!";
    }
    if(q==3)
    {
        cout<<"\n\t\t\t\t Please pay atleast three hours before the movie starts, otherwise your ticket will be cancelled.";
    }
}
node *String::newNode(int item)
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}
node* String::binarytree(node* root, int key)
{
    if (root == NULL || root->key == key)
      return root;
   if (root->key < key)
      return binarytree(root->right, key);
   return binarytree(root->left, key);
}
node* String::insert(struct node* node, int key){
   if (node == NULL) return newNode(key);
      if (key < node->key)
         node->left = insert(node->left, key);
      else if (key > node->key)
         node->right = insert(node->right, key);
   return node;
}
void String::traversetree(struct node *root){
   if (root != NULL){
      traversetree(root->left);
      printf("\n\t\t\t\t %d is available.", root->key);
      traversetree(root->right);
   }
}
void Movie::insertticket(int sn,string m,string n,string mn,int s,int p,int sbp_d[4],int sbg_d[4])
{
     T_icket *t,*a;
     a=new T_icket;
     a->SrNo=sn;
     a->movie=m;
     a->name=n;
     a->mobNo=mn;
     a->slot=s;
     a->pincode=p;
     a->next=NULL;
     for(int i=0;i<4;i++)
     {
         a->sbp[i]=a->sbg[i]=-1;
     }
     for(int i=0;i<4;i++)
     {
         a->sbp[i]=sbp_d[i];
         a->sbg[i]=sbg_d[i];
     }

     t=h;
     if(h==NULL)
     {
         h=a;
     }
     else
     {
         while(t->next!=NULL)
         {
             t=t->next;
         }
         t->next=a;
     }

}

int main()
{
    Movie m;
    {
        time_t t;time(&t);
        tm* timePtr = localtime(&t);

        cout<<" Current time: ";
        cout<<timePtr->tm_hour<<":"<<timePtr->tm_min<<":"<<timePtr->tm_sec<<endl;
        cout << " Current Date: " << timePtr->tm_mday<<"\/"<< timePtr->tm_mon + 1<<"\/"<< timePtr->tm_year+1900 << endl;

         fstream file;
        file.open("C:\\Users\\user\\Desktop\\e1.xls",ios::app);
        if(file)
        {
            file<<timePtr->tm_mday<<"\/"<< timePtr->tm_mon + 1<<"\/"<< timePtr->tm_year + 1900;
        }
        file.close();

	}
	m.home();

    return 0;
}
