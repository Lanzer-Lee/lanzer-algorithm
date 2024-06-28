from collections import deque

class GraphAdjacentMatrix():
    def __init__(self,vertices:list[int]|None,edges:list[list[int]]|None):
        self.vertices:list[int]=[]
        self.adj_mat:list[list[int]]=[]
        for vertex in vertices:
            self.add_vertex(vertex)
        for edge in edges:
            self.add_edge(edge[0],edge[1])

    def size(self)->int:
        return len(self.vertices)

    def add_vertex(self,val:int):
        n=self.size()
        self.vertices.append(val)
        new_row=[0]*n
        self.adj_mat.append(new_row)
        for row in self.adj_mat:
            row.append(0)

    def add_edge(self,i:int,j:int):
        if i<0 or j<0 or i>=self.size() or j>=self.size() or i==j:
            raise IndexError('edge vertex index error')
        self.adj_mat[i][j]=1
        self.adj_mat[j][i]=1

    def remove_vertex(self,index:int):
        if index<0 or index>=self.size():
            raise IndexError('vertex index error')
        self.vertices.pop(index)
        self.adj_mat.pop(index)
        for row in self.adj_mat:
            row.pop(index)

    def remove_edge(self,i:int,j:int):
        if i<0 or j<0 or i>=self.size() or j>=self.size() or i==j:
            raise IndexError('edge vertex index error')
        self.adj_mat[i][j]=0
        self.adj_mat[j][i]=0

    def print(self):
        print(self.vertices)
        for row in self.adj_mat:
            print(row)

class Vertex():
    def __init__(self,val:int) -> None:
        self.val=val

class GraphAdjacentList():
    def __init__(self,edges:list[list[Vertex]]|None=None) -> None:
        self.adj_list=dict[Vertex,list[Vertex]]()
        if edges is not None:
            for edge in edges:
                self.add_vertex(edge[0])
                self.add_vertex(edge[1])
                self.add_edge(edge[0],edge[1])

    def vals_to_vertices(self,values:list[int])->list[Vertex]:
        return [Vertex(value) for value in values]

    def size(self)->int:
        return len(self.adj_list)
    
    def add_vertex(self,vertex:Vertex):
        if vertex in self.adj_list:
            return
        self.adj_list[vertex]=[]

    def add_edge(self,v1:Vertex,v2:Vertex):
        if v1 not in self.adj_list or v2 not in self.adj_list or v1==v2:
            raise ValueError('edge vertex error')
        self.adj_list[v1].append(v2)
        self.adj_list[v2].append(v1)

    def remove_vertex(self,v:Vertex):
        if v not in self.adj_list:
            raise ValueError()
        self.adj_list.pop(v)
        for vertex in self.adj_list:
            if v in self.adj_list[vertex]:
                self.adj_list[vertex].remove(v)

    def remove_edge(self,v1:Vertex,v2:Vertex):
        if v1 not in self.adj_list or v2 not in self.adj_list or v1==v2:
            raise ValueError('edge vertex error')
        self.adj_list[v1].remove(v2)
        self.adj_list[v2].remove(v1)

    def bfs(self,start_vertex:Vertex)->list[Vertex]:
        res=[]
        visited=set[Vertex]([start_vertex])
        queue=deque[Vertex]([start_vertex])
        while len(queue)>0:
            vertex=queue.popleft()
            res.append(vertex)
            for v in self.adj_list:
                if v in visited:
                    continue
                queue.append(v)
                visited.add(v)
        return res
    
    def _dfs(self,visited:set[Vertex],res:list[Vertex],vertex:Vertex):
        res.append(vertex)
        visited.add(vertex)
        for v in self.adj_list[vertex]:
            if v in visited:
                continue
            self._dfs(visited,res,v)
    
    def dfs(self,start_vertex:Vertex)->list[Vertex]:
        res=[]
        visited=set[Vertex]()
        self._dfs(visited,res,start_vertex)
        return res

    def print(self):
        for vertex in self.adj_list:
            values=[v.val for v in self.adj_list[vertex]]
            print(f"{vertex.val}:{values}")

def main():
    vertices = [1, 3, 2, 5, 4]
    edges = [[0, 1], [0, 3], [1, 2], [2, 3], [2, 4], [3, 4]]
    graph=GraphAdjacentMatrix(vertices,edges)
    graph.print()
    graph.add_vertex(6)
    graph.add_edge(5,4)
    graph.print()
    print('----------')
    graph2=GraphAdjacentList()
    vertices=graph2.vals_to_vertices([1,3,2,5,4])
    for vertex in vertices:
        graph2.add_vertex(vertex)
    edges=[
        [vertices[0],vertices[1]],
        [vertices[0],vertices[3]],
        [vertices[1],vertices[2]],
        [vertices[2],vertices[3]],
        [vertices[2],vertices[4]],
        [vertices[3],vertices[4]]
    ]
    for edge in edges:
        graph2.add_edge(edge[0],edge[1])
    graph2.print()
    res=graph2.bfs(vertices[0])
    for vertex in res:
        print(vertex.val)
    print('---')
    res.clear()
    res=graph2.dfs(vertices[0])
    for vertex in res:
        print(vertex.val)

if __name__=='__main__':
    main()