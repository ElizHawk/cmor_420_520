using JuMP
using HiGHS, Ipopt

# max c' * x 
# s.t. A * x = b, x ≥ 0
model = Model(HiGHS.Optimizer)
# model = Model(Ipopt.Optimizer)
A = [1 1 9 5; 3 5 0 8; 2 0 6 13]
b = [7, 3, 5]
c = [1, 3, 5, 2]

@variable(model, x[1:4] >= 0)
@constraint(model, A * x .== b)
@objective(model, Min, c' * x)
print(model)

optimize!(model)
@assert is_solved_and_feasible(model)
objective_value(model)


# Knapsack problem; binary constraints
model = Model(HiGHS.Optimizer)
set_silent(model)
n = 5
capacity = 10.0
profit = [5.0, 3.0, 2.0, 7.0, 4.0]
weight = [2.0, 8.0, 4.0, 2.0, 5.0]
unregister(model, :x)
@variable(model, x[1:n], Bin)
@objective(model, Max, profit' * x)
@constraint(model, weight' * x <= capacity)
optimize!(model)
@assert is_solved_and_feasible(model)
println("Objective is: ", objective_value(model))
println("Solution is:")
for i in 1:n
    print("x[$i] = ", round(Int, value(x[i])))
    println(", c[$i] / w[$i] = ", profit[i] / weight[i])
end
chosen_items = [i for i in 1:n if value(x[i]) > 0.5]



# quadratic constraints
model = Model(Ipopt.Optimizer)
set_silent(model)
@variable(model, x)
@variable(model, y >= 0)
@variable(model, z >= 0)
@objective(model, Max, x)
@constraint(model, x + y + z == 1)
@constraint(model, x * x + y * y - z * z <= 0)
@constraint(model, x * x - y * z <= 0)
optimize!(model)
Test.@test is_solved_and_feasible(model)
print(model)

println("Objective value: ", objective_value(model))
println("x = ", value(x))
println("y = ", value(y))
Test.@test objective_value(model) ≈ 0.32699 atol = 1e-5
Test.@test value(x) ≈ 0.32699 atol = 1e-5
Test.@test value(y) ≈ 0.25707 atol = 1e-5

