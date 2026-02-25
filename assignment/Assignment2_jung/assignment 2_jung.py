from typing import List

class Problem1:
    def solve(self, s: str, t: str) -> str:
        result = 0
        
        # s의 모든 문자를 XOR
        for char in s:
            result ^= ord(char)
        
        # t의 모든 문자를 XOR
        for char in t:
            result ^= ord(char)
        
        # 남은 값이 추가된 문자
        return chr(result)

class Problem2:
    def solve(self, cookies: List[int], k: int) -> int:
        # 최적 분배 찾기
        n = len(cookies)
        children = [0] * k  # 각 아이가 받은 쿠키 수
        min_unfairness = float('inf')
        
        # 쿠키를 내림차순으로 정렬
        cookies.sort(reverse=True)
        
        def backtrack(idx):
            nonlocal min_unfairness
            
            # 모든 쿠키를 분배했을 때
            if idx == n:
                max_cookies = max(children)
                min_unfairness = min(min_unfairness, max_cookies)
                return
            
            # 현재 최대값이 이미 min_unfairness 이상이면 탐색 중단
            if max(children) >= min_unfairness:
                return
            
            # 현재 쿠키를 각 아이에게 주기
            for i in range(k):
                # 이전 아이와 같은 값이면 중복 탐색 방지
                if i > 0 and children[i] == children[i-1]:
                    continue
                
                children[i] += cookies[idx]
                backtrack(idx + 1)
                children[i] -= cookies[idx]
        
        backtrack(0)
        return min_unfairness

class Problem3:
    def solve(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        # 그래프 구성
        graph = [[] for _ in range(n)]
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        
        # restricted 노드를 set으로 변환
        restricted_set = set(restricted)
        
        # DFS로 탐색
        visited = set([0])
        
        def dfs(node):
            count = 1
            
            for neighbor in graph[node]:
                if neighbor not in visited and neighbor not in restricted_set:
                    visited.add(neighbor)
                    count += dfs(neighbor)
            
            return count
        
        return dfs(0)

if __name__ == "__main__":
    ## Problem 1
    problem_solver_1 = Problem1()

    # Test case 1
    result1 = problem_solver_1.solve("abcd", "abccd")
    print(f"Test 1: {result1}")
    
    # Test case 2
    result2 = problem_solver_1.solve("", "y")
    print(f"Test 2: {result2}")
    
    # 올바른 Test case 1
    result3 = problem_solver_1.solve("abcd", "abecd")
    print(f"Test 3: {result3}")
    
    ## Problem 2
    problem_solver_2 = Problem2()
    
    # Test case 1
    result1 = problem_solver_2.solve([8, 15, 10, 20, 8], 2)
    print(f"Test 1: {result1}")
    print(f"Explanation: [8, 15, 8] = 31 and [10, 20] = 30, max = 31")
    print()
    
    # Test case 2
    result2 = problem_solver_2.solve([6, 1, 3, 2, 2, 4, 1, 2], 3)
    print(f"Test 2: {result2}")
    print(f"Explanation: [6, 1] = 7, [3, 2, 2] = 7, [4, 1, 2] = 7, max = 7")
    print()
    
    # Additional test cases
    result3 = problem_solver_2.solve([1, 2, 3, 4, 5], 2)
    print(f"Test 3: {result3}")
    
    result4 = problem_solver_2.solve([10, 10], 2)
    print(f"Test 4: {result4}")
    
    ## Problem 3
    problem_solver_3 = Problem3()
    
    # Test case 1
    n = 7
    edges = [[0,1], [1,2], [3,0], [4,3], [0,5], [5,6]]
    restricted = [4, 5]
    result1 = problem_solver_3.solve(n, edges, restricted)
    print(f"Test 1: {result1}")
    print(f"Explanation: Nodes reachable from 0: [0, 1, 2, 3]")
    print()
    
    # Test case 2
    n = 5
    edges = [[0,1], [1,2], [2,3], [3,4]]
    restricted = [2]
    result2 = problem_solver_3.solve(n, edges, restricted)
    print(f"Test 2: {result2}")
    print(f"Explanation: Nodes reachable from 0: [0, 1]")
    print()
    
    # Test case 3
    n = 3
    edges = [[0,1], [1,2]]
    restricted = []
    result3 = problem_solver_3.solve(n, edges, restricted)
    print(f"Test 3: {result3}")
    print(f"Explanation: All nodes reachable")