#include "Stock.h"

Stock::Stock(void)
{
    head = NULL;
}

bool Stock::stockLoad(std::string fileName){
    ifstream fin;
    string a,b,c;
    int x,y;

    fin.open(fileName, ios::in);

    string line;
    stock_node st;
    if(fin.is_open()){

        while ( getline(fin, line) ){
            stringstream linestream(line);
            if(linestream){
                linestream>>a>>b>>c;
            }

            st.name = a;
            st.cost = stoi(b);
            st.shares = stoi(c);
            appendNode(st);
        }
    }
    else
        cout << "failed to open"<<endl;

    fin.close();
    return 0;
}

// fucntion to insert node at the beginning of the list

void Stock::insertNode(stock_node x){

    stock_node* new_node = new stock_node;

    new_node->name = x.name;
    new_node->cost = x.cost;
    new_node->shares = x.shares;
    new_node->next = head;

    head = new_node;

    return;
}


void Stock::appendNode(stock_node x) {
    stock_node* new_node = new stock_node;

    new_node->name = x.name;
    new_node->cost = x.cost;
    new_node->shares = x.shares;
    new_node->next = NULL;

    stock_node* last;

    if (head == NULL){
        head = new_node;
        return;
    }

    last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;

    return;
}


void Stock::stockprint(){
    stock_node * temp = head;
    while (temp)
    {
        cout<< temp->name << " "<< temp->cost << " "<< temp->shares<<"->"<<endl;
        temp = temp->next;
    }
}


void Stock::returnMiddleofList(){
    struct stock_node *slow_ptr = head;
    struct stock_node *fast_ptr = head;

    if (head!=NULL)
    {
        while (fast_ptr->next != NULL )
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }

        cout<<"name: "<< slow_ptr->name<<" cost: "<< slow_ptr->cost<< " shares: "<<slow_ptr->shares<< endl;
    }

}

void Stock::splitList(){

    stock_node * first = head;
    stock_node * second = NULL;

    stock_node * fast, * slow;
    slow = fast = head;

    if(head == NULL){
        return;
    }

    while(fast){
        if (fast->next)
            fast =  fast->next->next;
        else
            break;
        slow = slow->next;
    }

    second = slow->next;
    slow->next = NULL;

    printList(first);
    cout<<endl;
    printList(second);

    return;

}

void Stock::printList(stock_node* temp){
    while(temp){
        cout<< temp->name<<" "<< temp->cost<<" "<<temp->shares<<"->";
        temp = temp->next;
    }
    cout<< endl;
    return;
}

Stock::~Stock(void)
{
}
