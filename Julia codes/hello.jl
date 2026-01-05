
function hello_v1()
    println("Hello world")
end

hello_v2() = println("hello world")

hello_v3 = () -> println("hello world")

# four different ways to 
# run "hello world"
println("hello world")
hello_v1()
hello_v2()
hello_v3()

