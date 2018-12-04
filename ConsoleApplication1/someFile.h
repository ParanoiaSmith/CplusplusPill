// 'pragma' tells the compiler information
// 'pragma once' tells only read one time
// That's because for avoiding include header loops
// The same function as:
//#ifndef SOMEFILE_H
//#define SOMEFILE_H
//#endif //SOMEFILE_H
// These 2 ways are almost indistinguishable
// Popular named 'guards'
// Some coders suggest use both ¯\(°_o)/¯
#pragma once

{
	int i
