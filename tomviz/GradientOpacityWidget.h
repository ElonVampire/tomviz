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
#ifndef tomvizGradientOpacityWidget_h
#define tomvizGradientOpacityWidget_h

#include <QWidget>

#include <vtkNew.h>

/**
 * \brief Similar to HistogramWidget but keeps everything client side
 * (no proxy infrastructure is used). Displays a 1D gradient opacity
 * function.
 *
 */

//// TODO
//1. Review need for side buttons (range, etc.).
//2. Set default tf to all ones (no gradient thresholding).
//3. Serialize/ deserialize.
//4. Remove setInputData (if unnecessary). 

class vtkChartGradientOpacityEditor; 
class vtkContextView;
class vtkEventQtSlotConnect;
class vtkPiecewiseFunction;
class vtkObject;
class vtkTable;
class QVTKOpenGLWidget;

namespace tomviz {

class GradientOpacityWidget : public QWidget
{
  Q_OBJECT

public:
  explicit GradientOpacityWidget(QWidget* parent_ = nullptr);
  ~GradientOpacityWidget() override;

  void setLUT(vtkPiecewiseFunction* transferFunc);

  virtual void setInputData(vtkTable* table, const char* x_, const char* y_);

signals:
  void mapUpdated();

public slots:
  virtual void onOpacityFunctionChanged();

protected:

  vtkNew<vtkChartGradientOpacityEditor> m_histogramColorOpacityEditor;
  vtkNew<vtkContextView> m_histogramView;
  vtkPiecewiseFunction* m_scalarOpacityFunction = nullptr;
  vtkNew<vtkEventQtSlotConnect> m_eventLink;

private:
  void renderViews();

  QVTKOpenGLWidget* m_qvtk;
};

}
#endif // tomvizGradientOpacityWidget_h
