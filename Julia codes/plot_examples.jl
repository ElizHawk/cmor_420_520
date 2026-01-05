using Plots

# data to plot
x = LinRange(0, 1, 100)
f(x) = cos(10 * x) * exp(-x)

# creating two plots side-by-side using plot handles
t = 0.5
p1 = plot()
p2 = plot()
plot!(p1, x, f.(x), label="First function")
scatter!(p1, [t], [f(t)])
plot!(p2, x, -f.(x), label="Second function", linestyle=:dash)
scatter!(p2, [t], [-f(t)])
xlabel!(p1, "x")
title!(p1, "This is the title")
ylabel!(p1, "y")
plot(p1, p2)

# create a gif or animation 
anim = @animate for i = 1:length(x) 
    t = x[i]
    p1 = plot()
    p2 = plot()
    plot!(p1, x, f.(x), label="First function")
    scatter!(p1, [t], [f(t)])
    plot!(p2, x, -f.(x), label="Second function", linestyle=:dash)
    scatter!(p2, [t], [-f(t)])
    xlabel!(p1, "x")
    title!(p1, "This is the title")
    ylabel!(p1, "y")
    plot(p1, p2)
end
gif(anim)


# create a 2D contour plot
x = LinRange(0, 1, 100)
y = LinRange(0, 1, 100)
f(x,y) = sin(pi * x) * sin(pi * y)
c = [f(x[i], y[j]) for i = 1:length(x), j = 1:length(y)]
contourf(x, y, c)

