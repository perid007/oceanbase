/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OCEANBASE_SHARE_VECTOR_OB_DISCRETE_VECTOR_H_
#define OCEANBASE_SHARE_VECTOR_OB_DISCRETE_VECTOR_H_

#include "share/vector/ob_discrete_format.h"
#include "share/vector/vector_op_util.h"

namespace oceanbase
{
namespace common
{

template<typename BasicOp>
class ObDiscreteVector final: public ObDiscreteFormat
{
public:
  using VecTCBasicOp = BasicOp;
  using VectorType = ObDiscreteVector<VecTCBasicOp>;
  using VecOpUtil = VectorOpUtil<VectorType>;

  ObDiscreteVector(int32_t *lens, char **ptrs, sql::ObBitVector *nulls)
    : ObDiscreteFormat(lens, ptrs, nulls)
  {}

  int default_hash(BATCH_EVAL_HASH_ARGS) const override;
  int murmur_hash(BATCH_EVAL_HASH_ARGS) const override;
  int murmur_hash_v3(BATCH_EVAL_HASH_ARGS) const override;

  int murmur_hash_v3_for_one_row(EVAL_HASH_ARGS_FOR_ROW) const override;
  int null_first_cmp(VECTOR_ONE_COMPARE_ARGS) const override;
  int null_last_cmp(VECTOR_ONE_COMPARE_ARGS) const override;
  int no_null_cmp(VECTOR_NOT_NULL_COMPARE_ARGS) const override final;
  int null_first_mul_cmp(VECTOR_MUL_COMPARE_ARGS) const override final;
  int null_last_mul_cmp(VECTOR_MUL_COMPARE_ARGS) const override final;
  int null_first_cmp_batch_rows(VECTOR_COMPARE_BATCH_ROWS_ARGS) const override;
  int no_null_cmp_batch_rows(VECTOR_COMPARE_BATCH_ROWS_ARGS) const override;
};

} // end namespace common
} // end namespace oceanbase
#endif // OCEANBASE_SHARE_VECTOR_OB_DISCRETE_VECTOR_H_
