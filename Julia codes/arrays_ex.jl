using LinearAlgebra
using StaticArrays
using BenchmarkTools

n = 10
A =  randn(n,n)
B =  randn(n,n)
x =  ones(n)

y= zeros(n,100)

function A_B_inverse(A,B,x,y)
    for i in 1:100
        y[:,i]=(A+B)\x
    end
end

function A_inverse_B_inverse(A,B,x,y)
    for i in 1:100
        y[:,i]=(A\x)+(B\x)
    end
end


@btime A_B_inverse($A,$B,$x,$y)
@btime A_inverse_B_inverse($A,$B,$x,$y)