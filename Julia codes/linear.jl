
function LinearFunc(x)
    m=2;
    b=5;
    return m*x+b
end

function LinearFunc_v2(x...)
    m=2;
    b=5;
    @show m,b
    return @. m*x+b
end