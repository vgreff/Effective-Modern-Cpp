// MemoryBlock.h
#pragma once
#include <iostream>
#include <algorithm>

class MemoryBlock
{
public:

   // Simple constructor that initializes the resource.
   explicit MemoryBlock(size_t length)
      : _length(length)
      , _data(new int[length])
   {
      std::cout << "In MemoryBlock(size_t). length = "
                << _length << "." << std::endl;
   }

   // Destructor.
   ~MemoryBlock()
   {
      std::cout << "In ~MemoryBlock(). length = "
                << _length << ".";

      if (_data != nullptr)
      {
         std::cout << " Deleting resource.";
         // Delete the resource.
         delete[] _data;
      }

      std::cout << std::endl;
   }

   // Copy constructor.
   MemoryBlock(const MemoryBlock& other)
//       : _data(nullptr), _length(0)
   {
      std::cout << "In MemoryBlock(const MemoryBlock&). length = "
                << other._length << ". Copying resource." << std::endl << "   ";

      //std::copy(other._data, other._data + _length, _data);
      *this = other;
   }

   // Copy assignment operator.
   MemoryBlock& operator=(const MemoryBlock& other)
   {
      std::cout << "In operator=(const MemoryBlock&). length = "
                << other._length << ". Copying resource. " ;

      if (this != &other)
      {
         // Free the existing resource.
         delete[] _data;
         std::cout << "DEL length=" << _length << " ";

             _length = other._length;
         _data = new int[_length];
         std::copy(other._data, other._data + _length, _data);
      }
      std::cout << std::endl;
      return *this;
   }
   // Move constructor.
   MemoryBlock(MemoryBlock&& other) noexcept
//       : _data(nullptr), _length(0)
   {
       std::cout << "In MemoryBlock(MemoryBlock&&). length = "
                 << other._length << ". Moving resource." << std::endl << "   ";

       //*this = std::move(other); 
       *this = std::forward<MemoryBlock>(other);
   }

   // Move assignment operator.
   MemoryBlock& operator=(MemoryBlock&& other) noexcept
   {
       std::cout << "In operator=(MemoryBlock&&). length = "
                 << other._length << ".  ";

       if (this != &other)
       {
           // Free the existing resource.
           std::cout << "DEL length=" << _length << " ";
           delete[] _data;

           // Copy the data pointer and its length from the
           // source object.
           _data = other._data;
           _length = other._length;

           // Release the data pointer from the source object so that
           // the destructor does not free the memory multiple times.
           other._data = nullptr;
           other._length = 0;
       }
       std::cout << std::endl;
       return *this;
   }

   // Retrieves the length of the data resource.
   size_t size() const
   {
      return _length;
   }

private:
   size_t _length = 0 ; // The length of the resource.
   int* _data = nullptr; // The resource.
};
