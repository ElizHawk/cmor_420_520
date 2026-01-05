using BenchmarkTools

# ========= Example 1 =========
struct Point2D{T<:Real}
    x::T
    y::T
end

mynorm(x, y) = sqrt(x^2 + y^2)

function calc_mynorm()
    mynorms = zeros(100)
    x = randn(100)
    y = randn(100)
    for i in 1:100
        mynorms[i] = mynorm(x[i], y[i])
    end
    return mynorms
end

function calc_mynorm2()
    points = [Point2D(randn(), randn()) for i in 1:100]
    mynorms = zeros(100)
    for i in 1:100
        mynorms[i] = mynorm(points[i].x, points[i].y)
    end
    return mynorms
end
#println("timings of calc_mynorm")
#@btime calc_mynorm(); # reference
#println("timings of calc_mynorm2")
#@btime calc_mynorm2();

# ========= Example 2 ========= 
function mysum()
    val = 0.0
    for j = 1:1000
        val += sin(j)
    end
    return val
end

scaling = 1.0
function mysum2()
    val = 0.0
    for j = 1:1000
        val += scaling * sin(j)
    end
    return val
end

println("timings of mysum")
@btime mysum(); # reference
println("timings of mysum2")
@btime mysum2();

# ========= Example 3 ========= 

x = randn(10)
println("timings of sum(x)")
@btime sum(x);
y = Real[]
for i in 1:10
    push!(y, randn())
end
println("timings of sum(y)")
@btime sum(y);


# ========= Example 4 ========= 
function calc_mynorm3()
    mynorms = zeros(100)
    xy = randn(2, 100)
    for i in 1:100
        pt = xy[:, i]
        mynorms[i] = mynorm(pt[1], pt[2])
    end
    return mynorms
end
println("timings of calc_mynorm")
@btime calc_mynorm();
println("timings of calc_mynorm3")
@btime calc_mynorm3();