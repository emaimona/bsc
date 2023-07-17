package main
import (
    "fmt"
    "time"
)

func main() {
	add := make(chan request)
	multiply := make(chan request)
	
	go func() {
        for i := 0; i < 3; i++ {
			time.Sleep(500 * time.Millisecond)
			req := request{i+2,i+3,make(chan int)}
			add <- req
			result:= <- req.resp
			fmt.Println("(add) g1 sent", req.first, req.second, "received", result)
		}
    }()
	
	go func() {
        for i := 0; i < 3; i++ {
			time.Sleep(500 * time.Millisecond)
			req := request{i+2,i+3,make(chan int)}
			multiply <- req
			result:= <- req.resp
			fmt.Println("(multiply) g2 sent", req.first, req.second, "received", result)
		}
    }()
	
	L: for {
        select {
        case msg := <-add:  
			result:= msg.first + msg.second
			msg.resp <- result
			fmt.Println("(add) Main received ", msg.first, msg.second,"sent result ",result)			
		case msg := <-multiply:
			result:= msg.first * msg.second
			msg.resp <- result
			fmt.Println("(multiply) Main received ", msg.first, msg.second,"sent result ",result)
        case <- time.After(3 * time.Second):
			fmt.Println("Timeout, Quit")
			break L
		}
    }
}

type request struct{
	first int
	second int
	resp chan int
}

	