import tomviz.operators


class TestOperator(tomviz.operators.Operator):

    def transform_scalars(self, data):
        self.progress.message = 'Is there anyone out there?'
