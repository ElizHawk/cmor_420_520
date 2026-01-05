# A = uvᵀ
struct RankOneMatrix{T} <: AbstractMatrix{T}
    u::Vector{T}
    v::Vector{T}
end

Base.size(A::RankOneMatrix) = (length(A.u), length(A.v))
Base.getindex(A::RankOneMatrix, i, j) = A.u[i] * A.v[j]

function LinearAlgebra.mul!(b::AbstractVector, 
                            A::RankOneMatrix, 
                            x::AbstractVector)
    # uvᵀ * x = u * (vᵀx)
    b .= dot(A.v, x) .* A.u
end

A = RankOneMatrix(rand(3), randn(4))
x = Vector(1:4)
b = zeros(3)
mul!(x, A, b)

# timing
using LinearAlgebra
using BenchmarkTools
A = RankOneMatrix(randn(100), randn(200))
b = zeros(size(A, 1))
x = randn(size(A, 2))
@btime mul!($b, $A, $x)
@btime mul!($b, $(Matrix(A)), $x)

# verification
u = randn(10)
v = randn(20)
A = u * v'
isapprox(A, RankOneMatrix(u, v))
