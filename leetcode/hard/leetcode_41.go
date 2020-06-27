func firstMissingPositive(nums []int) int {
    if len(nums)==0 {
        return 1
    }
    // 两层while循环
    for {
        startIndex := -1
        var curV int
        for i:=0; i< len(nums);i++ {
            if nums[i] < 1 || nums[i] > len(nums) {
                continue 
            }
            if nums[i] != i+1 {
                startIndex = i
                curV = nums[i]
            }
        }
        if startIndex == -1 {
            break
        }
        nums[startIndex] = -1
        for {
            if curV < 1 || curV > len(nums) {
                break;
            }
            temp := nums[curV-1]
            if temp == curV {
                break;
            }
            nums[curV-1] = curV;
            curV = temp;
        }
    }

    for i :=0; i < len(nums); i++ {
        if nums[i] != i+1 {
            return i+1
        }
    }
    return len(nums)+1;
}
