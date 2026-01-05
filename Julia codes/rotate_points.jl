using StaticArrays
using BenchmarkTools

x = randn(1_000_000)
y = randn(1_000_000)

xy= SVector{2}.(x,y)

function rotate_points!(xy::AbstractVector{<:SVector{2}})
    for i in eachindex(xy)
        theta = randn()
        R = @SMatrix [cos(theta) -sin(theta); 
            sin(theta) cos(theta)]
        xy[i] = R * xy[i]  
    end
end

using StaticArrays
using StructArrays
struct Point2D{T} <: FieldVector{2, T}
    x::T
    y::T
end
xy = StructArray{Point2D}((x, y))