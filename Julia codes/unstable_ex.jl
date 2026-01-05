using BenchmarkTools

struct Vector_Set{T<:Real}
    length::Int64
    x::Vector{T}
    y::Vector{T}
    function Vector_Set{T}(length::Int64,x_init::T,y_init::T) where T<:Real
        println("New vector set")
        x=[x_init+i for i in 1:length]
        y=[y_init+i for i in 1:length]
        return new(length,x,y)
    end
end

length=10
V=Vector_Set{Float64}(length,1.0,5.0)

mynorm(x, y) = sqrt(x^2 + y^2)

function calc_mynorm2(x::AbstractVector, y::AbstractVector)
    return @. mynorm(x,y)
end

@btime calc_mynorm2(V.x, V.y);

