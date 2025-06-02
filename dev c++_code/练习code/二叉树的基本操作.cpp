//链式二叉树的定义
typedef char BTDataType;//使用typedef关键字给char类型取了一个别名BTDataType

typedef struct BTNode  //使用Struct关键字定义了一个名为BTNode的结构体
{
	BTDataType data;     //二叉树节点的数据域，用于存储具体的数据值
	struct BTNode* left;   //二叉树节点的左子叶节点指针，指向左子叶节点
	struct BTNode* right;  //二叉树节点的右子叶节点指针，指向右子叶节点 
 } BTNode;  //使用BTNode作为该结构体类型的别名 
 
 // 二叉树的遍历
 
 //前序建立二叉树的函数
 BTNode*  CreatBinaryTreePre(BTDataType* a,int n,int* pi)
 {
 	//如果数组索引超出数组长度，返回空指针
	 if(*pi >= n)
	 {
	 	return NULL;
	  } 
	  
	  //如果当前位置的值为‘#’，表示当前位置为空节点，将索引向后移动，并返回空指针
	  if(a[*pi] == '#')
	  {
	  	(*pi)++;
	  	return NULL;
	   } 
	   
	   //动态分配一个新的二叉树节点
	   BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	   
	   //如果内存分配成功
	   if(root)
	   {
	   	//将当前位置的值存储到新节点的数据域中
		   root->data = a[(*pi)++];
		   
		//递归调用CreateBinaryTreePre函数，构建新节点的左字树 
		   root->left = CreateBinaryTreePre{a,n,pi};
		   
		//递归调用CreateBinaryTreePre函数，构建新节点的右子树 
		   root->right = CreateBinaryTreePre{a,n,pi};
		} 
	   
	   else
	   {
	   	//如果内存分配失败，打印错误信息并退出程序
		   perror("malloc fail!");
		   exit(-1); 
	   }
	   
	   return root;  //返回根节点 
	    
 }
 
 
 //主函数
 int main()
 {
 	BTNode* root;  //定义二叉树的根节点指针
	BTDataType a[] = {'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#','\0'};
	
	int n = strlen(a);
	int pi = 0;   //定义一个变量用于追踪数组的索引位置
	
	//调用CreateBinaryTreePre函数，传入数组a、数组长度n和索引位置的指针pi
	//生成二叉树，并返回根节点指针
	
	root = CreateBinaryTreePre(a,n,&pi);
	
	
	return 0; 
  } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
