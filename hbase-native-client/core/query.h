/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include <memory>

#include "core/filter.h"

namespace hbase {

/**
 * Base class for read RPC calls (Get / Scan).
 */
class Query {
 public:
  Query() = default;
  Query(const Query &query) {
    // filter can be a custom subclass of Filter, so we do not do a deep copy here.
    filter_ = query.filter_;
  }

  Query &operator=(const Query &query) {
    filter_ = query.filter_;
    return *this;
  }

  virtual ~Query() {}

  void SetFilter(std::shared_ptr<Filter> filter) { filter_ = filter; }

  const std::shared_ptr<Filter> filter() const { return filter_; }

 protected:
  std::shared_ptr<Filter> filter_ = nullptr;
};

}  // namespace hbase
