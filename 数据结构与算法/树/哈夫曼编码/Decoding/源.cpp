#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <deque>
#include <map>
using namespace std;
class huffmanTree
{
private:
	struct Node//定义哈弗曼树的节点
{
	char x;
	int prob;//出现概率
	Node* later1;//0
	Node* later2;//1
	Node(char x = 0, int prob = 0, Node*later1 = NULL, Node*later2 = NULL) :x(x), prob(prob), later1(later1), later2(later2) {}

};
	struct cmp1//优先队列最小值优先的比较函数
	{
		bool operator ()(Node *&a, Node *&b) {
			return (*a).prob > (*b).prob;//最小值优先  
		}
	};
	Node* root;//建立好后的哈夫曼树
	map<char, string> charTocode;//建立哈夫曼树后的各个字母编码
	string textString;//要编码的文本
	string codeString;//要译码的文本
	int charcount;//编码后一共有多少01位；
public:
	huffmanTree()
	{
		root = NULL;
		charcount = 0;
	}
	~huffmanTree()
	{
		destroyTree(root);
	}
	string compress(string buffer)
	{
		char temp = 0;
		string result;
		int basic = 1;
		for (int i = buffer.size() - 1; i>=0 ; i--)
		{
			if (basic == 128)//每7个字符清零
			{
				result = temp + result;
				basic = 1;
				temp = 0;
			}
			if (buffer[i] == '1')
				temp = temp | basic;
			basic *= 2;
		}
		result = temp + result;
		return result;
	}
	string decompress(string &buffer)
	{
		string result;
		int count = charcount;
		for (int i = buffer.size()-1; i >=0; i--)
		{
			int basic = 1;
			char temp = buffer[i];
			for (int j = 0; j < 7 && count > 0; j++)
			{
				if ((int)(temp & basic) != 0)
					result = '1' + result;
				else
					result = '0' + result;
				basic *= 2;
				count--;
			}	
		}
		return result;
	}
	void readtext(string address)
	{
		ifstream input(address.c_str());
		string temp((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
		textString = temp;
		input.close();
	}
	void readcode(string address)
	{
		ifstream input(address.c_str());
		string temp((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
		codeString = decompress(temp);
		input.close();
	}
	void outputcode(string address)
	{
		ofstream output(address.c_str());
		string buffer;
		for (int i = 0; i < textString.size(); i++)
		{
			buffer += charTocode[textString[i]];
		}
		charcount = buffer.size();
		output << compress(buffer);
		output.close();
	}
	void outputtext(string address)
	{
		if (root!=NULL)
		{
			ofstream output(address.c_str());
			Node* subroot = root;
			for (int i = 0; i < codeString.size(); i++)
			{
				if (subroot->later1 == NULL && subroot->later2 == NULL)
				{
					output << subroot->x;
					subroot = root;
				}
				if (codeString[i] == '0')
				{
					subroot = subroot->later1;
				}
				else
				{
					subroot = subroot->later2;
				}
			}
			output << subroot->x;
			output.close();
		}
	}
	void countProb(priority_queue<Node*, vector<Node*>, cmp1> &pq)
	{
		map<char, int> countChar;
		map<char, int>::iterator it;
		for (int i = 0; i < textString.size(); i++)
		{
			it = countChar.find(textString[i]);
			if (it != countChar.end())
			{
				(*it).second++;
			}
			else
			{
				countChar.insert(make_pair(textString[i], 1));
			}
		}
		for (it = countChar.begin(); it != countChar.end(); it++)
		{
			Node* temp = new Node((*it).first, (*it).second);
			pq.push(temp);
		}
	}
	void buildTree(priority_queue<Node*, vector<Node*>, cmp1> &pq)//建立哈弗曼树
	{
		while (pq.size() > 1)
		{
			Node *tree1 = pq.top();
			pq.pop();
			Node *tree2 = pq.top();
			pq.pop();
			Node* temp = new Node(0, (*tree1).prob + (*tree2).prob, tree2, tree1);
			pq.push(temp);
		}
		root = pq.top();
	}
	void dfs(Node* subroot, map<char, string> &charTocode, string a)
	{
		if (subroot)
		{
			if (subroot->later1 == NULL && subroot->later2 == NULL)
			{
				charTocode[subroot->x] = a;
			}
			else
			{
				string left = a + '0';
				string right = a + '1';
				dfs(subroot->later1, charTocode, left);
				dfs(subroot->later2, charTocode, right);
			}
		}
	}
	void destroyTree(Node*root)
	{
		if (root != NULL)
		{
			destroyTree(root->later1);
			destroyTree(root->later2);
			delete root;
			root = NULL;
		}
	}
	void huffmanCoding(string input_address,string outaddress)//读取文本并输出
	{
		//读取文本
		readtext(input_address);//获取文本文件的所有字符	
		//计算字符出现的次数 并建立最小堆
		priority_queue<Node*, vector<Node*>, cmp1> pq;//装有字符节点的优先队列
		countProb(pq);
		//用最小堆建立哈弗曼树
		buildTree(pq);
		//用哈夫曼树建立哈夫曼编码表
		string a;
		dfs(root, charTocode, a);
		//输出编码后的文本
		outputcode(outaddress);
	}
	void huffmanDeCoding(string input_address, string outaddress)
	{
		if (root != NULL)
		{
			readcode(input_address);//获取文本文件的所有01串
			outputtext(outaddress);//输出译码后的字符
		}
		
	}
};

int main()
{
	string input_address1 = "huffmanCoding inputfile.txt";
	string output_address1 = "huffmanCoding outputfile.txt";
	string input_address2 = "huffmanDeCoding inputfile.txt";
	string output_address2 = "huffmanDeCoding outputfile.txt";
	huffmanTree testTree;
	testTree.huffmanCoding(input_address1, output_address1);
	testTree.huffmanDeCoding(input_address2,output_address2);
	return 0;
}
