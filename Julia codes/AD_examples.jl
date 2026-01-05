using ForwardDiff

# example 
function heron(x0)
    @assert x0 > 0
    x = x0   
    for _ in 1:25
        x = 0.5 * (x + x0 / x)
    end
    return x
end

deriv_heron(x) = 
    ForwardDiff.derivative(heron, x)

# plotting the AD function 
using Plots
x = LinRange(.1, 1, 100)
plot(x,heron.(x))
plot!(x, deriv_heron.(x))    

# partial derivatives
f(x, y) = x * y
dfdx(x, y) = 
    ForwardDiff.derivative(x -> f(x, y), x)
dfdy(x, y) = 
    ForwardDiff.derivative(y -> f(x, y), y)

# higher derivatives    
f(x) = 0.5 * x' * x
grad_f(x) = ForwardDiff.gradient(f, x)
hessian_f(x) = ForwardDiff.jacobian(grad_f, x)

# timings
using BenchmarkTools
@btime heron($.1)
@btime deriv_heron($.1)

f(x) = sum(x)
@btime f($(randn(10)))
@btime ForwardDiff.gradient($f, $(randn(10)))


f(x)=sin(pi*x)
dfdx(x) = ForwardDiff.derivative(f,x)
d2fdx(x) = ForwardDiff.derivative(dfdx,x)

x=LinRange(-1,1,1000)
using Plots
plot(x,d2fdx.(x))