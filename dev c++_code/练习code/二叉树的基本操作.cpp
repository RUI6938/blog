//��ʽ�������Ķ���
typedef char BTDataType;//ʹ��typedef�ؼ��ָ�char����ȡ��һ������BTDataType

typedef struct BTNode  //ʹ��Struct�ؼ��ֶ�����һ����ΪBTNode�Ľṹ��
{
	BTDataType data;     //�������ڵ�����������ڴ洢���������ֵ
	struct BTNode* left;   //�������ڵ������Ҷ�ڵ�ָ�룬ָ������Ҷ�ڵ�
	struct BTNode* right;  //�������ڵ������Ҷ�ڵ�ָ�룬ָ������Ҷ�ڵ� 
 } BTNode;  //ʹ��BTNode��Ϊ�ýṹ�����͵ı��� 
 
 // �������ı���
 
 //ǰ�����������ĺ���
 BTNode*  CreatBinaryTreePre(BTDataType* a,int n,int* pi)
 {
 	//������������������鳤�ȣ����ؿ�ָ��
	 if(*pi >= n)
	 {
	 	return NULL;
	  } 
	  
	  //�����ǰλ�õ�ֵΪ��#������ʾ��ǰλ��Ϊ�սڵ㣬����������ƶ��������ؿ�ָ��
	  if(a[*pi] == '#')
	  {
	  	(*pi)++;
	  	return NULL;
	   } 
	   
	   //��̬����һ���µĶ������ڵ�
	   BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	   
	   //����ڴ����ɹ�
	   if(root)
	   {
	   	//����ǰλ�õ�ֵ�洢���½ڵ����������
		   root->data = a[(*pi)++];
		   
		//�ݹ����CreateBinaryTreePre�����������½ڵ�������� 
		   root->left = CreateBinaryTreePre{a,n,pi};
		   
		//�ݹ����CreateBinaryTreePre�����������½ڵ�������� 
		   root->right = CreateBinaryTreePre{a,n,pi};
		} 
	   
	   else
	   {
	   	//����ڴ����ʧ�ܣ���ӡ������Ϣ���˳�����
		   perror("malloc fail!");
		   exit(-1); 
	   }
	   
	   return root;  //���ظ��ڵ� 
	    
 }
 
 
 //������
 int main()
 {
 	BTNode* root;  //����������ĸ��ڵ�ָ��
	BTDataType a[] = {'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#','\0'};
	
	int n = strlen(a);
	int pi = 0;   //����һ����������׷�����������λ��
	
	//����CreateBinaryTreePre��������������a�����鳤��n������λ�õ�ָ��pi
	//���ɶ������������ظ��ڵ�ָ��
	
	root = CreateBinaryTreePre(a,n,&pi);
	
	
	return 0; 
  } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
