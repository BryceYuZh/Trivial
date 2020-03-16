#include <iostream>

using namespace std;
typedef struct lnode{

    int data; //数据域

    struct lnode *next; //指针域

}LNode,*LinkList;
//定义头指针变量：LinkedList L;

LinkList L;



LinkList Create_LinkList1() // 从头部插入节点
{
    L = NULL;						//定义L为空链表
    int x;									//设数据元素为int类型
    LNode *s;
    cin >> x;
    while(x!=-1){
        s = (LNode*)malloc(sizeof(LNode));	//申请内存
        if(s == NULL){
            cout << "申请内存空间失败！";
            break;
        }
        s->data = x;
        s->next = L;						//若是第一个结点，则将NULL赋给s，从第二个开始，
        //因为是从头部插入，所以s->next指向的是上一轮定义的结点
        L = s;								//头指针指向最新的结点s
        cin >> x;
    }
    return L;								//返回头指针，通过头指针可以遍历该链表
}

//在表尾插入结点
LinkList Create_LinkList2(){
    L = NULL;
    LNode *s;	//定义结点
    LNode *r;	//定义尾指针，永远指向最后一个结点
    int x;
    s = (LNode*)malloc(sizeof(LNode));	//定义头结点，申请内存
    if(s==NULL){
        printf("申请内存空间失败！");
    }
    s->next = NULL;
    L = s;	//头指针指向头结点
    r = s; 	//尾指针指向头结点		注：此时链表里面没有数据结点
    cin >> x;
    while(x != -1){
        s = (LNode*)malloc(sizeof(LNode));
        if(s==NULL){
            printf("申请内存空间失败！");
            break;
        }
        s->data = x;
        s->next = NULL;
        r->next = s;	//将尾结点的next指向最新的结点
        r = s;			//尾指针指向最新的结点
        cin >> x;
    }
    return L;
}

//获取链表长度(带头结点)
int Length_LinkList1(LinkList L){
    LNode *p = L;
    int j=0;
    while(p->next){
        p = p->next;
        j++;
    }
    return j;
}

//按序号查找单链表中的第i个元素结点，找到返回指针，否则返回空 （带头结点）
LNode *Get_LinkList(LinkList L,int i){
    LNode *p = L;
    int j=0;
    while(j<i&&p->next!=NULL){
        p = p->next;
        j++;
    }
    if(j==i)
        return p;
    else
        return NULL;
}


// 按值查找（带头结点）
LNode *Locate_LinkList(LinkList L,int x){
    LNode *p = L->next;
    while(p!=NULL&&p->data!=x){
        p = p->next;
    }
    return p;
}

//插入（前插结点）（带头结点）（失败返回0，成功返回1）
int Insert_LinkList(LinkList L,int i,int x){
    LNode *p,*s;
    p = Get_LinkList(L,i-1);	//获取第i-1个结点
    if(p==NULL){
        printf("参数i错误！\n");
        return 0;
    }
    else{
        s = (LNode*)malloc(sizeof(LNode));	//申请、填装结点
        if(s==NULL){
            printf("申请内存空间失败！");
            return 0;
        }
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}


int Delete_LinkList(LinkList L,int i) {
    LinkList p, s;
    p = Get_LinkList(L, i - 1);    //获取第i-1个节点
    if (p == NULL) {
        printf("第i-1个结点不存在\n");
        return -1;
    } else if (p->next == NULL) {
        printf("第i个结点不存在");
        return 0;
    } else {
        s = p->next;
        p->next = s->next;
        free(s);    //释放*s;
        return 1;
    }
}


void Find(LinkList L){
    LNode *p = L->next;
    int i=0;
    while(p){
        i++;
        printf("---->|Node%d->data:%d|\n",i,p->data);
        p = p->next;
    }
}