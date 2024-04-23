#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

/* ����� "�������� ������" */
class BinaryTree {
public:
	class Node;

	BinaryTree();																// ����������� �� ���������
	BinaryTree(const BinaryTree& other);										// ����������� �����������

	virtual ~BinaryTree();														// ����������

	Node* GetRoot() const;														// ��������� ����� ������

	void ClearTree();															// ������� ������

	void DeleteSubtree(Node*& node);											// �������� ����������� ����

	bool isEmpty() const;														// �������� ������ �� �������

	BinaryTree CopySubtree(Node* from);											// ����������� ��������� ����

	int GetHeight(Node* node) const;											// ��������� ������ ������
	int GetHeight() const;

	int GetNumNodes(Node* node) const;											// ��������� ���������� ����� ������
	int GetNumNodes() const;

	virtual int GetMinKey(Node* node) const;									// ��������� ������������ ����� ������
	int GetMinKey() const;

	virtual int GetMaxKey(Node* node) const;									// ��������� ������������� ����� ������
	int GetMaxKey() const;

	virtual Node* AddNode(Node* node, const int key);							// ���������� ���� � ������
	void AddNode(const int key);

	virtual bool RemoveNode(Node*& node, const int key);						// �������� ���� �� ������ �� �����
	bool RemoveNode(const int key);

	bool isBalanced(Node* node);												// �������� ������ �� ������������������
	bool isBalanced();

	int GetSumAllKeys(Node* node) const;										// ��������� ����� ���� ������ �������
	int GetSumAllKeys() const;

	virtual int GetLevelByKey(Node* node, const int key) const;					// ��������� ������ ������� �� �����
	int GetLevelByKey(const int ket) const;

	std::vector<int> GetAllKeys(Node* node) const;								// ��������� �������, ����������� ��� ����� ������
	std::vector<int> GetAllKeys() const;

	void PrintTree() const;														// ����� � ������� ������ � �������������� ����
	void FillTreeData(Node* node, std::vector<std::vector<int>>& treeData, int level, int left, int right) const;

	void PrintLeaves(Node* node) const;											// ����� � ������� ������� ������
	void PrintLeaves() const;

	BinaryTree& operator=(const BinaryTree& other);								// �������� ������������

	int GetSize() const;														// ��������� ������� ������ (���������� �����)

private:
	Node* ProvokeFindParent(Node* node, const int key);
	int ProvokeGetLevelByKey(Node* node, const int data, int height) const;
	virtual void ProvokeDeleteRoot(Node*& node);
	void ProvokeClearSubtree(Node* node);

protected:
	Node* ProvokeCopy(Node* from);

protected:
	Node* m_root = nullptr;
	int m_size;
};

/* ����� "���� ��������� ������" */
class BinaryTree::Node {
private:
	int m_key;
	Node* m_left = nullptr;
	Node* m_right = nullptr;
	int m_height = 1;

public:
	Node();																		// ����������� (�� ���������)				
	Node(int key);																// ����������� (� �����������)

	~Node() = default;															// ����������

	int GetKey() const;															// ��������� �����
	void SetKey(const int key);													// ������������ �����

	int GetNumChildren();														// ��������� ���������� ������ �������� ����

	Node*& GetLeft();															// �������� ������ �������
	const Node* GetLeft() const;

	Node*& GetRight();															// �������� ������� �������
	const Node* GetRight() const;

	void SetLeft(Node* left);													// ������� ������ �������
	void SetRight(Node* right);													// ������� ������� �������
};