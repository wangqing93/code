func mySqrt(x int) int {
    if x==0 {
        return 0
    }
    //牛顿迭代法hh
    var res float64
    var times int
    times = 100
    res = float64(x)
    for i:=0; i< times; i++ {
        res = res - (res*res-float64(x))/(2*res)
    }
    return int(res)
}
