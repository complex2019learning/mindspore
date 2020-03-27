/**
 * Copyright 2019 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OPTIMIZER_PARALLEL_STEP_AUTO_PARALLEL_H_
#define OPTIMIZER_PARALLEL_STEP_AUTO_PARALLEL_H_

#include <vector>
#include <memory>
#include <string>
#include <map>
#include "ir/anf.h"
#include "optimizer/opt.h"
#include "pipeline/pipeline.h"
#include "optimizer/parallel/status.h"

namespace mindspore {
namespace parallel {
bool IsSplittableOperator(const std::string &);

bool IsAutoParallelCareNode(const CNodePtr &);

// main step of Auto-parallel
bool StepAutoParallel(const FuncGraphPtr &func_graph, const opt::OptimizerPtr &optimizer);

size_t GetLengthOfDataType(const TypePtr &type);

std::vector<bool> ExtractInputParameterByNode(const CNodePtr &node);

std::vector<std::vector<size_t>> ExtractInputAndOutputTypeLengthByNode(const CNodePtr &node);

Status ConstructCostGraphNodes(const std::vector<AnfNodePtr> &all_nodes, const FuncGraphPtr &root);

void ConstructCostGraphEdges(const std::vector<AnfNodePtr> &all_nodes);

void AugmentCostGraph(const std::vector<AnfNodePtr> &all_nodes);

Status ParallelStrategySearch(const std::vector<AnfNodePtr> &all_nodes, const FuncGraphPtr &root);

Status ParallelStrategyRecSearch(const std::vector<AnfNodePtr> &all_nodes, const FuncGraphPtr &root);

std::vector<std::vector<std::string>> RecInputTensorNames(const std::map<std::string, std::string>::iterator &it,
                                                          std::vector<std::vector<std::string>> input_tensor_names);

}  // namespace parallel
}  // namespace mindspore
#endif  // OPTIMIZER_PARALLEL_STEP_AUTO_PARALLEL_H_