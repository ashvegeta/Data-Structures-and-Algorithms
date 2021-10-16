def get_ways(grid_size,i,j,dp):
    if i==j and j==grid_size:  # if reached bottom right corner return 1
        return 1

    if dp[i][j]!=-1:
        return dp[i][j]  # if the grid point is already explored then return dp[i][j]

    right , down = 0 , 0  

    if j + 1 <= grid_size:
        right += get_ways(grid_size ,i ,j + 1,dp)  # recusrively traverse right and get no of routes 

    if i + 1 <= grid_size:
        down += get_ways(grid_size, i + 1, j, dp)  # recusrively traverse down and get no of routes 

    dp[i][j] = right + down # add no of routes obtained from traversing right and down and store that in dp[i][j]
    
    return dp[i][j] # return no of routes obtained from grid position (i,j)

def main():
    grid_size = 20
    dp = [[-1 for j in range(grid_size + 1)] for i in range(grid_size + 1)]
    print(get_ways(grid_size,0,0,dp))


if __name__ == "__main__":
    main()

    