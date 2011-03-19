/*
* Copyright (c) 2011 MLBA. All rights reserved.
*
* @MLBA_OPEN_LICENSE_HEADER_START@
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* @MLBA_OPEN_LICENSE_HEADER_END@
*/



#ifndef QBLOCKRUNNABLE_H_
#define QBLOCKRUNNABLE_H_

#include <QRunnable>
#include "../dispatch.h"

#ifdef HAS_BLOCKS

/**
  Provides a QRunnable Implementation for use with
  blocks on clang or lambda functions in C++0x

  Please see the documentation for QRunnable for the
  functionality of the autoDelete flags as well.
  */
class QBlockRunnable : public QRunnable {

public:
	/**
	  Constructs a new QBlockRunnable using the given block, e.g.

	  @code
	  QBlockRunnable task(${cout << "Hello World\n";});
	  @endcode
	  */
	QBlockRunnable(dispatch_block_t b);
	QBlockRunnable(const QBlockRunnable&);
	~QBlockRunnable();
	virtual void run();

private:
	class Private;
	Private* d;

};

#endif

#endif /* QBLOCKRUNNABLE_H_ */