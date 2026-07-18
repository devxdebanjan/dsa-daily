# We have several processes to run. Each process places a load (given as an integer) on the server it runs on. The total load of a server is the sum of loads of all processes assigned to it.

# You have two servers available. Assign all processes to the two servers such that the absolute difference between their total loads is minimized.

# Write a function that, given an integer array A (length N) where each element represents a process load, returns the minimal absolute difference between the two servers’ total loads.

# Input:
# A = [1, 2, 3, 4]

# Output:
# 0

# Explanation:
# Server 1: [1, 4] = 5
# Server 2: [2, 3] = 5

# Difference = |5 - 5| = 0

# Input:
# A = [5, 8, 6]

# Output:
# 3

# Explanation:
# Server 1: [8] = 8
# Server 2: [5, 6] = 11

# Difference = |11 - 8| = 3

def minDifference(A):
    total = sum(A)

    dp = [False] * (total + 1)
    dp[0] = True

    for x in A:
        for s in range(total, x - 1, -1):
            if dp[s - x]:
                dp[s] = True

    for s in range(total // 2, -1, -1):
        if dp[s]:
            return total - 2 * s