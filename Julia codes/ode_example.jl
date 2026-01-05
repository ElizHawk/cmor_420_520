using OrdinaryDiffEq # or DifferentialEquations

function brusselator(du, u, p, t)
    B = 4
    y1, y2 = u
    du[1] = 1 + y1^2 * y2 - (B+1) * y1
    du[2] = B * y1 - y1^2 * y2
end
u0 = [1.5, 3.0]
tspan = (0.0, 25.0)
prob = ODEProblem(brusselator, u0, tspan)
sol = solve(prob, Tsit5())

using Plots
plot(sol, linewidth=2)
scatter!(sol.t, getindex.(sol.u, 1), ms=2, label=nothing)
scatter!(sol.t, getindex.(sol.u, 2), ms=2, label=nothing)



function lorenz!(du, u, p, t)
    du[1] = 10.0 * (u[2] - u[1]) # du1/dt
    du[2] = u[1] * (28.0 - u[3]) - u[2] # du2/dt
    du[3] = u[1] * u[2] - (8 / 3) * u[3] # du3/dt
end

u0 = [1.0; 0.0; 0.0]
tspan = (0.0, 100.0)
prob = ODEProblem(lorenz!, u0, tspan)
sol = solve(prob, Tsit5())

using Plots

@gif for t in LinRange(24, 25, 100)
    u = sol(t)
    plot(sol, idxs = (1, 2, 3))
    scatter!([u[1]], [u[2]], [u[3]], legend=false)
end