#pragma once

#include "CompilerHelper.h"

#include <llvm/IR/Module.h>

namespace dev
{
namespace eth
{
namespace jit
{

class Stack : public CompilerHelper
{
public:

	Stack(llvm::IRBuilder<>& builder);
	virtual ~Stack();

	llvm::Value* get(size_t _index);
	void set(size_t _index, llvm::Value* _value);
	void pop(size_t _count);
	void push(llvm::Value* _value);

	static size_t maxStackSize;

private:

	llvm::Function* m_push;
	llvm::Function* m_pop;
	llvm::Function* m_get;
	llvm::Function* m_set;

	llvm::Value* m_arg;
};


}
}
}


