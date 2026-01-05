using Plots

x = LinRange(-1, 1, 1000)
f(x, t) = sin(pi * (x - t))

@gif for t in LinRange(0, 2 * pi, 50)
    plot(x, f.(x, t))
end
