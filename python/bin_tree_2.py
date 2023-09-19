"""
이진트리 저장
    0. 일차원 배열로 저장
    1. 인접 리스트로 저장
    2. 연결 리스트로 저장
"""
## 연결 리스트 -> 개발용
class TreeNode():
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


    # 삽입함수
    def insert(self, childNode):
        if not self.left:
            self.left = childNode
            return
        
        if not self.right:
            self.right = childNode
            return
        
        return
    

    # 전위 순회
    def preorder(self):
        # 아무것도 없는 트리르 조회할 때
        if self != None:
            print(self.value, end=' ')
            # 왼쪽이 있다면 왼쪽 자식 조회
            if self.left:
                self.left.preorder()
            # 오른쪽이 있다면 오른쪽 자식 조회
            if self.right:
                self.right.preorder()
    

    # 중위 순회
    def inorder(self):
        # 아무것도 없는 트리르 조회할 때
        if self != None:
            # 왼쪽이 있다면 왼쪽 자식 조회
            if self.left:
                self.left.inorder()
            
            print(self.value, end=' ')

            # 오른쪽이 있다면 오른쪽 자식 조회
            if self.right:
                self.right.inorder()
    

    # 후위 순회
    def postorder(self):
        # 아무것도 없는 트리르 조회할 때
        if self != None:
            # 왼쪽이 있다면 왼쪽 자식 조회
            if self.left:
                self.left.postorder()
            # 오른쪽이 있다면 오른쪽 자식 조회
            if self.right:
                self.right.postorder()
            print(self.value, end=' ')


arr = [1, 2, 1, 3, 2, 4, 3, 5, 3, 6]

nodes = [TreeNode(i) for i in range(0, 14)]
for i in range(0, len(arr), 2):
    parentNode = arr[i]
    childNode = arr[i + 1]
    nodes[parentNode].insert(nodes[childNode])

## 인접 리스트
list_nodes = [[] for _ in range(0, 14)]
for i in range(0, len(arr), 2):
    parentNode = arr[i]
    childNode = arr[i + 1]
    list_nodes[parentNode].append(childNode)

# 트릭
for li in list_nodes:
    for _ in range(len(li), 2):
        li.append(None)

# for i in range(len(list_nodes)):
#     print(list_nodes[i])

def preorder(nodeNumber):
    if nodeNumber == None:
        return

    # 전위
    print(nodeNumber, end=' ')
    preorder(list_nodes[nodeNumber][0])
    # 중위
    # preorder(nodeNumber, end=' ')
    preorder(list_nodes[nodeNumber][1])
    # 후위
    # preorder(nodeNumber, end=' ')

preorder(1)
