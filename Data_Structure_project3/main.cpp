#include <iostream>
#include <string>

#include "IOCtr.h"
#include "FamilyTree.h"
#include "Member.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

/*
 * class Member{
 *     enum MarrageState = {MARRIED , UNMARRIED , DIVORCED };
 *     string name , couple;
 *     int birth, death;
 *     bool sex;
 *     
 *     vector<Member> child
 * }
 */

void ShowOption(){
    
    printf("0)  Show me the Family Tree.\n");
    printf("1)  I give birth to a child.\n");
    printf("2)  I have adopted a child.\n");
    printf("3)  I have adopted a relative child.\n");
    printf("4)  I have got married.\n");
    printf("5)  I divorced my wife.\n");
    printf("6)  I died.\n");
    printf("7)  I'm gonna to do gene test.\n");
    printf("8)  I'd like to append brief introduction.");


    printf("What Happens to you? $ ");
}
FamilyTree *tree;
// or tree[N] , map<string, *FamilyTree>  ? 

void Initial(){  
    // if FuYao want to recover the total family tree from txt , code here.
    Member ancestor("GaoJirong", 1949, -1, Member::MARRIED, 0);
    tree = new FamilyTree(ancestor);
}

void InputChild(string name ,bool fromRelavtive)
{
    string child_name;int birthyear;
    string child_sex;
    printf("What's your child's name ? :"); cin>>child_name;
    printf("What's your child's birthyear ?:");cin>>birthyear;
    printf("Is your baby a boy or a girl ?: "); cin>>child_sex;
    Member *baby = new Member(child_name, birthyear, child_sex);
    tree->GiveBirth(name, child_name, birthday,); // father 's name , baby's info
//FamilyTree::GiveBirth();
    if ( fromRelavtive){
        string relative_name;
        printf("Who is the child adopted from ? :");cin>>relative_name;
        tree->RemoveChild(relative_name, bab);
    }
}
int main(){

    Initial();
    printf("+----------------------------+\n");
    printf("|  The Family Tree of Gao    |\n");
    printf("+----------------------------+\n");
    
    while (true){
        string name;
        printf("What's your name ?:\t");cin>>name;
        ShowOption();
        int op; scanf("%d", &op);
        if ( op==0 ){
            tree->PrintTree();
        }   else
        if ( op==1){
            InputChild(name,0);
        }   else
        if ( op==2){
            InputChild(name,0);
        }
        if ( op==3){
            InputChild(name,1);
        }
        if ( op==4){
            string wifeName;
            printf("Please Enter your wife's name. :"); cin>>wifeName;
            tree->GetMarried(name, wifeName);
        }
        if ( op==5){
            string checker;
            printf("Did you sure ? (y/n): "); cin>>checker;
            if ( checker=="y") tree->Divorce(name);
        }  
        if ( op==6){
            tree->Die(name);
            printf("OOOOhhh ~~~ I'm sorry to hear that : ");
        }  
        if ( op==7){
            string child_name;
            printf("Which child did you want to test ? : ");
            cin>>child_name;
            double rate = rand()/32768.0;
// the men was 10% probility to be green 
            if ( rate < 0.1){
                printf("I'm sorry , the child is not yours~~. \n");
                tree->RemoveChild(name, child_name);
            }   else 
                printf("Congratulation , the child is yours !!\n");
        }
        if ( op==8){
            printf("Please write your introduction below, NO NEWLINE before the end.\n");
            string info; cin>>info;
            tree->appendIntroduction(name, info);
        }  
    }
    return 0;
}