#  Project 3: 家谱管理  
用树型结构实现家族成员信息管理：建立、删除、查询、统计、打印等  
##  数据结构与算法  
###  1.一个节点的所有子节点均为其孩子  
###  2.每个节点的信息：姓名、性别、配偶、孩子数、出生死亡日期、生平信息、身份(enum)  
###  3.建树主要操作：  
-建立祖节点  
-族长继承    
-权限管理   
-结婚  
-生子  
-离婚  
-复婚  
-再婚  
-替别人养孩子      
-过继  
-领养  
-死亡   
-添加生平信息  
-添加相关资料  
###  4.查询主要操作：  
-权限控制，公开，私密   
-节点内信息：配偶，孩子数...  
-节点间信息：两节点关系
###  5.打印树：合适的方式返回数据结构至main函数  

## 程序流程  
1.初始化  
2.登陆   
3.根据不同的权限显示不同的界面    
4.操作  
5.保存数据  
6.退出   

   
## 新需求： 
1.FamilyTree要有构造函数支持这样的操作——newfamily("laowangjiapu");        
2.FamilyTree有一个成员(String)记录家族的大事，同时重载<<和>>运算符，要求能够从逗号分隔值文件(*.csv)输入输出;      
3.Member需要password来记录成员的密码，初始密码默认为生日，以及修改密码等操作。     
4.Member需要一个String记录生平，操作同(2).       
5.Member还需要一个函数，将所有信息保存在一个string里面返回。    
6.member的构造函数能够从（5）的string里面直接恢复数据。  