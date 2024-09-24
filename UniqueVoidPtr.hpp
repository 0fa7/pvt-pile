#pragma once

#include <memory>

using UniqueVoidPtr = std::unique_ptr<void, void (*)(void const*)>;

template <typename T> void VoidPtrDeleter(void const* data)
{
    T const* p = static_cast<T const*>(data);
    delete p;
}

template <typename T> UniqueVoidPtr MakeUniqueVoidPtr(T* ptr)
{
    return UniqueVoidPtr(ptr, VoidPtrDeleter<T>);
}