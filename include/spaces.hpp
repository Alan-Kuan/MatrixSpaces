#ifndef SPACES_HPP
#define SPACES_HPP

#include "matrix.hpp"
#include "elimination.hpp"

Matrix column_space(const Matrix &M);

Matrix row_space(const Matrix &M);

Matrix nullspace(const Matrix &M);

Matrix left_nullspace(const Matrix &M);

#endif
