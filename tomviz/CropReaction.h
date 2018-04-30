/******************************************************************************

  This source file is part of the tomviz project.

  Copyright Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/
#ifndef tomvizCropReaction_h
#define tomvizCropReaction_h

#include <pqReaction.h>

class QMainWindow;

namespace tomviz {
class DataSource;

class CropReaction : public pqReaction
{
  Q_OBJECT

public:
  CropReaction(QAction* parent, QMainWindow* mw);

  void crop(DataSource* source = nullptr);

protected:
  void updateEnableState() override;
  void onTriggered() override { crop(); }

private:
  Q_DISABLE_COPY(CropReaction)
  QMainWindow* m_mainWindow;
};
} // namespace tomviz

#endif
