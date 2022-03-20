package main

import (
	"fmt"
	"unsafe"
)

func main() {
	//fmt.Println("Hello, World!")
	var stockcode = 123
	var enddate = "2020-12-31"
	var url = "Code=%d&endDate=%s"
	var target_url = fmt.Sprintf(url, stockcode, enddate)
	fmt.Println(target_url)

	const (
		a = "abc"
		b = len(a)
		c = unsafe.Sizeof(a)
	)
	println(a, b, c)
}
