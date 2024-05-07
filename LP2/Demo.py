import heapq

class Node:
    
    def __init__(self, parent, position, g, h):
        self.parent = parent
        self.position = position
        self.g = g
        self.h = h
        self.f = g+h

    def __lt__(self, other):
        return self.f < other.f

def astar(matrix, start_loc, end_loc):
    
    openlist = []
    closed_list = set()

    start_node = Node(None, start_loc, 0, 0)
    heapq.heappush(openlist, (start_node.f, start_node))

    while openlist:

        current = heapq.heappop(openlist)[1]
        current_pos = current.position
        closed_list.add(current_pos)

        if(current_pos == end_loc):
            path = []
            while current:
                path.append(current.position)
                current = current.parent
            path.reverse()
            return path

        directions = {(0,1), (0,-1), (1,0), (-1,0)}

        for d in directions:
            new_position = (current_pos[0]+d[0], current_pos[1]+d[1])
            if(
                new_position[0] < 0 or new_position[0] >= len(matrix)
                or new_position[1] < 0 or new_position[1] >= len(matrix[0])
                or matrix[new_position[0]][new_position[1]] == 1 or
                new_position in closed_list 
            ):
                continue
        
            new_node = Node(current, new_position, current.g+1, abs(new_position[0]-current_pos[0])+abs(new_position[1]-current_pos[1]))

            heapq.heappush(openlist, (new_node.f ,new_node))
    
    return path

matrix = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 1, 0, 1, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 1],
    [0, 1, 0, 0, 0, 0],
    [0, 0, 0, 1, 1, 0],  
]

# 1 -> obstacle ,0 -> empty space 
start_loc = (0, 0) #round brackets!!!!
end_loc = (5,5)

path = astar(matrix, start_loc, end_loc)

print(len(path))
print(path)
